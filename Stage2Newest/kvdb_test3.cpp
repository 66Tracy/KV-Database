#include<iostream>

#include "KVDBHandler.h"

#ifdef __cplusplus > 199711L 

#include <thread>
#include <chrono>
#define SLEEP(x) std::cout << "Wait for " << x << " secs..." << std::endl; \
    std::this_thread::sleep_for (std::chrono::seconds(x)); 
#else

#include<Windows.h>
#define SLEEP(x) std::cout << "Wait for " << x << " secs..." << std::endl; \
    Sleep(x * 1000)

#endif

#define GET(key) if (kvdb::KVDB_OK == kvdb::get(&kv, key, &value)) { \
		std::cout << value << std::endl; \
	} else { \
		std::cout << "'" << key << "' Not exists for GET!" << std::endl; \
    }

#define DEL(key) if (kvdb::KVDB_OK == kvdb::del(&kv, key)) { \
		std::cout << "Deletes '" << key << "'" << std::endl; \
	} else { \
		std::cout << "'" << key << "' Not exists for DEL!" << std::endl; \
    }

void test1() {
    std::string value;
    kvdb::KVDBHandler kv("kvdb_test3.dat");

    // 娴嬭瘯澶氭 EXPIRES 鎿嶄綔 
    set(&kv, "a", "1");
    expires(&kv, "a", 3);
    expires(&kv, "a", 5);
    expires(&kv, "a", 2);
   
    SLEEP(1);
    GET("a"); 

    SLEEP(2);
    GET("a");
}

void test2() {
    std::string value;
    kvdb::KVDBHandler kv("kvdb_test3.dat");

    // 娴嬭瘯 DEL 涓?EXPIRES 鎿嶄綔
    set(&kv, "b", "1");
    expires(&kv, "b", 5);
    expires(&kv, "b", 2); 

    SLEEP(3);
    DEL("b");

    set(&kv, "b", "2");
    expires(&kv, "b", 5);
    set(&kv, "b", "2");
    expires(&kv, "b", 2);

    SLEEP(1);

    DEL("b");
    expires(&kv, "b", 1);   // 娴嬭瘯 expires 涓€涓垹闄ょ殑鍊?
    
    SLEEP(2);
    GET("b");               

    set(&kv, "b", "3");
    expires(&kv, "b", 2);
    set(&kv, "b", "4");          // 娴嬭瘯 set 瑕嗙洊 expires 

    SLEEP(3);
    GET("b");
}

void test3_1() {
    // 娴嬭瘯 re-open銆乸urge
    std::string value;
    kvdb::KVDBHandler kv("kvdb_test3.dat");

    set(&kv, "c", "1");
    expires(&kv, "c", 2); 

    set(&kv, "d", "1");
    expires(&kv, "d", 2); 

    set(&kv, "e", "1");
    expires(&kv, "e", 4); 
    expires(&kv, "e", 2); 
}

void test3_2() {
    std::string value;
    kvdb::KVDBHandler kv("kvdb_test3.dat");

    GET("c");
    DEL("c");
    GET("d");

    SLEEP(3);

    GET("c");
    GET("d");
    GET("e");

    set(&kv, "c", "1");
    expires(&kv, "c", 1); 

    set(&kv, "d", "1");
    expires(&kv, "d", 4); 
    DEL("d");

    set(&kv, "e", "1");
    expires(&kv, "e", 10); 
    expires(&kv, "e", 4); 

    set(&kv, "f", "1");
    expires(&kv, "f", 1); 
    expires(&kv, "f", 4); 

    set(&kv, "g", "1");
    expires(&kv, "g", 1); 
    DEL("g");
    expires(&kv, "g", 1); 
    set(&kv, "g", "2");
    expires(&kv, "g", 4); 
    
    set(&kv, "h", "1");
    expires(&kv, "h", 1); 
    DEL("h");
    expires(&kv, "h", 1); 
    set(&kv, "h", "2");
    expires(&kv, "h", 1); 

    set(&kv, "i", "1");
    expires(&kv, "i", 1); 
    DEL("i");
    expires(&kv, "i", 1); 
    set(&kv, "i", "2");
    expires(&kv, "i", 1); 
    set(&kv, "i", "3");

    SLEEP(2);

    if (kvdb::KVDB_OK != purge(&kv)) {
        std::cout << "Failed to PURGE" << std::endl;
    }
    // Again!
    if (kvdb::KVDB_OK != purge(&kv)) {
        std::cout << "Failed to PURGE" << std::endl;
    }
}

void test3_3() {
    std::string value;
    kvdb::KVDBHandler kv("kvdb_test3.dat");

    GET("c");
    GET("d");
    GET("e");
    GET("f");
    GET("g");
    GET("h");
    GET("i");

    SLEEP(3);

    GET("c");
    GET("d");
    GET("e");
    GET("f");
    GET("g");
    GET("h");
    GET("i");
}

int main(int, char**) {
    test1();
    test2();
    test3_1();
    test3_2();
    test3_3();
    return 0;
}
