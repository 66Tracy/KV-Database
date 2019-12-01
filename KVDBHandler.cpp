#include "KVDBHandler.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdint.h>
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
	}
}

fstream& KVDBHandler::getAOF(){
	return AOF;
}

// Closes DB handler
KVDBHandler::~KVDBHandler(){
    AOF.close();
}

int kvdb::set(KVDBHandler *handler, const std::string &key, const std::string &value){
	fstream &AOF = handler->getAOF();
	AOF.seekg(0,ios::end);
			
	uint32_t key_length = key.length(), value_length = value.length();
	    	
	const char* key_c=NULL;
	const char* value_c=NULL;
	key_c = key.c_str();
	value_c = value.c_str();

	//this sentence will write a unsigned int32
	AOF.write(reinterpret_cast<char *>(&key_length), sizeof(uint32_t)); 
	AOF.write(reinterpret_cast<char *>(&value_length), sizeof(uint32_t));
	//AOF.write(reinterpret_cast<char *>(&key_c), key_length*sizeof(char));
	//AOF.write(reinterpret_cast<char *>(&value_c), value_length*sizeof(char));
	AOF<<key_c;
	AOF<<value_c;
	    	
	return 0;
}

int kvdb::get(KVDBHandler* handler, const std::string& key, std::string& value){	
	fstream &AOF = handler->getAOF();
	AOF.seekg(0,ios::beg);
	    	
	uint32_t key_length=key.length(), value_length=0;
	int if_find = 0;
	char tmp_key[256];
	//char *tmp_value=NULL, *record_value=NULL;
	char tmp_value[256], record_value[256];
	const char *key_c=key.c_str(), *value_c=value.c_str();
	    	
	while(AOF.peek()!=EOF){
		AOF.read(reinterpret_cast<char*>(&key_length),sizeof(uint32_t));
		AOF.read(reinterpret_cast<char*>(&value_length),sizeof(uint32_t));
				
		AOF.read(reinterpret_cast<char*>(&tmp_key),key_length*sizeof(char));
		tmp_key[key_length]='\0';//末尾置'\0' 
		
		if(!strcmp(tmp_key,key.c_str())){
			if(value_length==0){
				if_find=0;
				value.resize(0);
				memcpy(&value[0],"",0);
			}	
			else{
				if_find=1;
				value.resize(value_length);
				AOF.read(reinterpret_cast<char*>(&value[0]),value_length*sizeof(char));
			}
		}
		else{
			AOF.seekg(value_length,ios::cur);
		}
		
	}
		
		/*if(value_length!=0){
			//tmp_value=new char[value_length+1];	
			//AOF.read(reinterpret_cast<char*>(&tmp_value),value_length*sizeof(char));
			//tmp_value[value_length]='\0';
			value_length=strlen(record_value);
			value.resize(value_length);
			memcpy(&value[0],record_value,value_length);
		}*/
				
		/*if(!strcmp(tmp_key,key.c_str())){
			if(value_length = 0){//value长度为0 
				if_find = 0;
			}
			else{
				if_find = 1;
//				if(record_value){
//					delete []record_value;
//				}
				//record_value=new char[value_length+1];
				strcpy(record_value, tmp_value);
			}
		}
		//delete []tmp_value;
	}//while*/
			
	if(if_find == 1){
		//cout<<"find the file successfully:"<<endl;
		
		//delete []record_value;
		return 0;
	}
	else{
		//cout<<"can't find the file"<<endl;
		return 1;
	}
}

int kvdb::del(KVDBHandler* handler, const std::string& key){
    uint32_t key_length = key.length(), value_length = 0;
    string value;
    	
	if(get(handler,key,value)==0){
		set(handler,key,"");
		return 0;
	}
    	
    return 1;
}
