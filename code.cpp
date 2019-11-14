#include<iostream>
#include<fstream>
#include<string.h>
#include<stdint.h>
using namespace std;
	
	//handler
	class KVDBHandler {
	private:
	ifstream 	read_AOF;	
	ofstream 	creat;
	fstream 	write_AOF;
	string 		path_file;

    public:
        // Constructor, creates DB handler
        // @param db_file {const std::string&} path of the append-only file for database.
        KVDBHandler(const std::string& db_file){
        	path_file = db_file;
        	
        	//Try to open a the file;
        	write_AOF.open(db_file,ios::out|ios::in|ios::binary|ios::app);
        	
        	if(write_AOF.fail()){
        		cout<<"orginal file don't exit"<<endl<<"now creating..."<<endl;
        		
        		//if the file don't exit, 'creat'(ofstream) will creat the file
        		creat(db_file,ios::binary);
        		
        		//error path will lead to the fail of creat
        		if(creat.fail()){
        			cout<<"error path of file!"<<endl;
				}
				else{
					cout<<"creat succesfully"<<endl;
				}
				//then close the 'creat'(ofstream)
				creat.close();
				
				write_AOF.open(db_file,ios::out|ios::in|ios::binary|ios::app);
			}
			else{
				cout<<"open successfully"<<endl;
			}
		}
		
		fstream& get_write(){
			return write_AOF;
		}
		
		//Get the ostream
		ifstream& get_read(){
			read_AOF.open(path_file,ios::binary);
			return read_AOF;
		}
		
		void close_read(){
			read_AOF.close();
		}

        // Closes DB handler
        ~KVDBHandler(){
        	write_AOF.close();
        	creat.close();
        	read_AOF.close();
		}
    };
    
    // Set the string value of a key
    // @param handler {KVDBHandler*} the handler of KVDB
    // @param key {const std::string&} the key of a string
    // @param value {const std::string&} the value of a string
    // @return {int} return code
    int set(KVDBHandler* handler, const std::char* key, const std::char* value){
    	
    	uint32_t key_length = 0, value_length = 0;
    	
    	key_length = strlen(key);
    	value_length = strlen(value);
    	
    	//get the fstream to write the file
    	fstream set_file = handler->getfs();
    	//this sentence will write a unsigned int32
    	set_file.write(reinterpret_cast<char *>(&key_length), sizeof(unsigned int)); 
    	set_file.write(reinterpret_cast<char *>(&value_length), sizeof(unsigned int));
    	set_file<<key;
    	set_file<<value;
    	
    	return 1;
	}
	
    // Get the value of a key
    // @param handler {KVDBHandler*} the handler of KVDB
    // @param key {const std::string&} the key of a string
    // @param value {std::string&} store the value of a key after GET executed correctly
    // @return {int} return code    
    int get(KVDBHandler* handler, const std::string& key, std::string& value){
    	//get the 'read_AOF'(ifstream)
    	ifstream get_istream = handler->get_read();
    	
    	uint32_t key_length, value_length;
    	
    	int if_find = 0, if_exit = 0;
    	
    	char *tmp_key = NULL, *tmp_value = NULL, *record_value = NULL;
    	
		while(get_istream.peek()!=EOF){
			get_istream.read(reinterpret_cast<char*>(&key_length),sizeof(unsigned int));
			get_istream.read(reinterpret_cast<char*>(&value_length),sizeof(unsigned int));
			get_stream.read(reinterpret_cast<char*>(&tmp_key),key_length*sizeof(char));
			if(value_length!=-1){	
				get_stream.read(reinterpret_cast<char*>(&tmp_value),value_length*sizeof(char));
			}
			
			if(!strcmd(tmp_key,key)){
				if(value_length = -1){
					if_exit = -1;
				}
				else{
					if_exit = 1;
					strcpy(reacord_value, tmp_value);
				}
			}
		}
		
		if(if_exit == 1){
			cout<<"find the file successfullly:"<<endl;
			strcpy(value, record_value);
		}
		else{
			cout<<"can't find the file"<<endl;
		}
		handler->close_read();
	}
	
    // Delete a key
    // @param handler {KVDBHandler*} the handler of KVDB
    // @param key {const std::string&} the key to be deleted
    // @return {int} return code
    int del(KVDBHandler* handler, const std::string& key){
    	uint32_t key_length = 0, value_length = 0;
    	
    	key_length = strlen(key);
    	value_length = -1;
    	
		//get the fstream to write the file
    	fstream set_file = handler->getfs();
    	
    	//this sentence will write a unsigned int32
    	set_file.write(reinterpret_cast<char *>(&key_length), sizeof(unsigned int)); 
    	set_file.write(reinterpret_cast<char *>(&value_length), sizeof(unsigned int));
    	set_file<<key;
    	
    	return 1;
	}
