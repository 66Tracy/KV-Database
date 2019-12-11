#include "KVDBHandler.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<unordered_map>
#include<time.h>
#include<queue>
using namespace kvdb;
using namespace std;

KVDBHandler::KVDBHandler(const std::string& db_file)
{
	path_file = db_file;
        	
    //Try to open a the file;
    AOF.open(db_file.c_str(),ios::out|ios::in|ios::binary|ios::app);
        	
    if(AOF.fail()){
        cout<<"error path of file"<<endl;
	}
	else{
		cout<<"open successfully"<<endl;
		kvdb::setIndex(this);
	}
}

fstream& KVDBHandler::getAOF(){
	return AOF;
}

void KVDBHandler::reopen(){
	AOF.open(path_file.c_str(),ios::out|ios::in|ios::binary|ios::app);
        	
	if(AOF.fail()){
        cout<<"error path of file"<<endl;
        kvdb::setIndex(this);
	}
	else{
		cout<<"open successfully"<<endl;
	}
}
		
string KVDBHandler::getPath(){
	return path_file;
}

unordered_map<string,node1>& KVDBHandler::getIndex(){
	return Index;
}

priority_queue<node>& KVDBHandler::getTimeQueue(){
	return TimeQueue;
}

// Closes DB handler
KVDBHandler::~KVDBHandler(){
    AOF.close();
}

//---------------------------------------------------------------
int kvdb::clearOverDue(KVDBHandler* handler){
	time_t nowSeconds=time(NULL);
	
	priority_queue<node>& TimeQueue=handler->getTimeQueue();
	unordered_map<string,node1>& Index=handler->getIndex();

	while(!TimeQueue.empty() && TimeQueue.top().Time<nowSeconds){
		string key=TimeQueue.top().key;
		if(Index.count(key)!=0 && Index[key].Time<nowSeconds){
			del(handler,key);
		}
		TimeQueue.pop();
	}
	
	return KVDB_OK;
}

int kvdb::setIndex(KVDBHandler* handler){
	unordered_map<string,node1>& Index = handler->getIndex();
	priority_queue<node>& TimeQueue = handler->getTimeQueue();
	Index.clear();
	TimeQueue.clear();
	
	fstream& AOF=handler->getAOF();
	
	AOF.seekg(0,ios::beg);
	
	string key,value;
	int key_length, value_length, offset;
	time_t Time;
	
	while(AOF.peek()!=EOF){
		offset=AOF.tellg();
		AOF.read(reinterpret_cast<char*>(&key_length),sizeof(int));
		key.resize(key_length);
		AOF.read(reinterpret_cast<char*>(&value_length),sizeof(int));
		AOF.read(reinterpret_cast<char*>(&key[0]),key_length*sizeof(char));

		if(value_length==0){
			Index.erase(key);
		}	
		else if(value_length==-1){
			AOF.read(reinterpret_cast<char*>(&Time),sizeof(time_t));
			Index[key]=node1(offset,Time);
			TimeQueue.push(node(Time,key));
		}
		else{
			Index[key]=node1(offset,0);
			AOF.seekg(value_length,ios::cur);
		}
	}
	return KVDB_OK;
//	auto iter=catalog.begin();
//	while(iter!=catalog.end()){
//		//key=iter->first;
//		offset=iter->second;
//		AOF.seekg(offset,ios::beg);
//		AOF.read(reinterpret_cast<char*>(&key_length),sizeof(uint32_t));
//		key.resize(key_length);
//		AOF.read(reinterpret_cast<char*>(&value_length),sizeof(uint32_t));
//		value.resize(value_length);
//		AOF.read(reinterpret_cast<char*>(&key[0]),key_length*sizeof(char));
//		AOF.read(reinterpret_cast<char*>(&value[0]),value_length*sizeof(char));
//		cout<<"key:"<<key<<endl<<"value:"<<value<<endl<<"offset:"<<offset<<endl;
//		++iter;
//	}
}

int kvdb::set(KVDBHandler *handler, const std::string &key, const std::string &value){
	fstream &AOF = handler->getAOF();
	AOF.seekg(0,ios::end);
	int offset=AOF.tellg();
	int key_length = key.length(), value_length = value.length();
	    	
	const char* key_c=NULL;
	const char* value_c=NULL;
	key_c = key.c_str();
	value_c = value.c_str();

	AOF.write(reinterpret_cast<char *>(&key_length), sizeof(int)); 
	AOF.write(reinterpret_cast<char *>(&value_length), sizeof(int));
	AOF<<key_c;
	AOF<<value_c;
	
	unordered_map<string,node1>& Index = handler->getIndex();
	Index[key]=node1(offset,0);
	    	
	return KVDB_OK;
}

int kvdb::get(KVDBHandler* handler, const std::string& key, std::string &value){	
	clearOverDue(handler);
	
	unordered_map<string,node1>& Index = handler->getIndex();
	if(Index.count(key)==0)
		return KVDB_INVALID_KEY;
	
	node1 tmp=Index[key];	
	int offset=tmp.offset;
	fstream &AOF = handler->getAOF();
	AOF.seekg(offset,ios::beg);
	
	int key_length=0, value_length=0;
	
	AOF.read(reinterpret_cast<char*>(&key_length),sizeof(int));
	AOF.read(reinterpret_cast<char*>(&value_length),sizeof(int));
	AOF.seekg(key_length,ios::cur);
	value.resize(value_length);
	AOF.read(reinterpret_cast<char*>(&value[0]),value_length*sizeof(char));
	
	return KVDB_OK;
}

int kvdb::del(KVDBHandler* handler, const std::string& key){
    string value;
    	
	if(get(handler,key,value)==KVDB_OK){
		set(handler,key,"");
		unordered_map<string,node1>& Index = handler->getIndex();
		Index.erase(key);
		return KVDB_OK;
	}
    	
    return KVDB_INVALID_KEY;
}

int kvdb::purge(KVDBHandler* handler){
	clearOverDue(handler);
	
	string path2="tmp1.txt";
	KVDBHandler *handler2;
	handler2 = new KVDBHandler(path2);
	
	fstream& tmp_AOF=handler2->getAOF();
	fstream& AOF=handler->getAOF();
	unordered_map<string,node1>& Index = handler->getIndex();
	
	string key,value;
	int key_length, value_length;
	int offset;
	time_t Time;
		
	auto iter=Index.begin();
	while(iter!=Index.end()){
		node1 tmp=iter->second;
		offset=tmp.offset;
		Time=tmp.Time;
		AOF.seekg(offset,ios::beg);
		AOF.read(reinterpret_cast<char*>(&key_length),sizeof(int));
		key.resize(key_length);
		AOF.read(reinterpret_cast<char*>(&value_length),sizeof(int));
		value.resize(value_length);
		AOF.read(reinterpret_cast<char*>(&key[0]),key_length*sizeof(char));
		AOF.read(reinterpret_cast<char*>(&value[0]),value_length*sizeof(char));
		set(handler2,key,value);
		if(Time!=0){
			expires(handler2,key,Time);
		}
		++iter;
	}
	delete handler2;
	
	string new_path=handler->getPath();
	AOF.close();
	remove(new_path.c_str());
	rename(path2.c_str(), new_path.c_str());
	
	handler->reopen();
	
	return KVDB_OK;
}

int kvdb::expires(KVDBHandler* handler, const std::string& key, time_t n){
	string value;
	if(get(handler,key,value)==KVDB_INVALID_KEY)
		return KVDB_INVALID_KEY;
	
	fstream &AOF = handler->getAOF();
	priority_queue<node>& TimeQueue=handler->getTimeQueue();
	unordered_map<string,node1>& Index = handler->getIndex(); 
	
	AOF.seekg(0,ios::end);
	int key_length = key.length(), value_length = -1;
	time_t Time=n;//n为1970到过期的秒数 
	    	
	const char* key_c=NULL;
	key_c = key.c_str();

	AOF.write(reinterpret_cast<char *>(&key_length), sizeof(int)); 
	AOF.write(reinterpret_cast<char *>(&value_length), sizeof(int));
	AOF<<key_c;
	AOF.write(reinterpret_cast<char *>(&Time), sizeof(time_t));
	
	TimeQueue.push(node(Time,key));
	node1 tmp=Index[key];
	int offset=tmp.offset;
	Index[key]=node1(offset,Time);
	    	
	return KVDB_OK;
}
