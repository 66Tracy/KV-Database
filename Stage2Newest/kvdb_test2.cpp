#include<iostream>

#include "KVDBHandler.h"


void test1() {
    std::cout << "// test1" << std::endl;
    std::string value;
    kvdb::KVDBHandler kv("kvdb_test2.dat");

    kvdb::set(&kv, "key_r", "value_o");
    kvdb::set(&kv, "key_x", "value_r");
    kvdb::set(&kv, "key_phx", "value_ubzu");
    kvdb::set(&kv, "key_p", "value_sz");
    kvdb::set(&kv, "key_r", "value_cz");
    kvdb::set(&kv, "key_kmg", "value_d");
    kvdb::set(&kv, "key_v", "value_p");
    kvdb::set(&kv, "key_v", "value_sr");
    kvdb::set(&kv, "key_kmg", "value_ox");
    kvdb::set(&kv, "key_rf", "value_da");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_g", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_x", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ru", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::del(&kv, "key_ki");
    kvdb::set(&kv, "key_vg", "value_z");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_a", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_g", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_l", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::del(&kv, "key_kmg");
    kvdb::del(&kv, "key_l");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_x", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::del(&kv, "key_a");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ki", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_rf", "value_f");
    kvdb::set(&kv, "key_rf", "value_zapf");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_v", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_r", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::del(&kv, "key_xc");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_p", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_x", "value_b");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_xc", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_p", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::del(&kv, "key_p");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_v", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_v", "value_dsal");
    kvdb::del(&kv, "key_l");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_l", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_nrl", "value_s");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_g", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_nrl", "value_dn");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_r", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_phx", "value_dgzs");
    kvdb::set(&kv, "key_x", "value_ytl");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_yk", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_rf", "value_b");
    kvdb::del(&kv, "key_oeb");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_phx", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_g", "value_sq");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ru", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_p", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_yk", "value_a");
    kvdb::set(&kv, "key_v", "value_r");
    kvdb::del(&kv, "key_a");
    kvdb::del(&kv, "key_b");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_xc", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::del(&kv, "key_nrl");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_a", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_v", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_g", "value_xbu");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ki", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_xc", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_ru", "value_u");
    kvdb::set(&kv, "key_yk", "value_txgl");
    kvdb::set(&kv, "key_x", "value_y");
    kvdb::del(&kv, "key_ru");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_l", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_p", "value_ru");
    kvdb::del(&kv, "key_nrl");
    kvdb::set(&kv, "key_x", "value_i");
    kvdb::set(&kv, "key_v", "value_v");
    kvdb::set(&kv, "key_xc", "value_xihd");
    kvdb::set(&kv, "key_nrl", "value_db");
    kvdb::del(&kv, "key_a");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_kmg", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_wit", "value_q");
    kvdb::del(&kv, "key_kmg");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_x", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::del(&kv, "key_p");
    kvdb::del(&kv, "key_wit");
    kvdb::set(&kv, "key_wit", "value_z");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ki", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_b", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_oeb", "value_sh");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_vg", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_rf", "value_zxu");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_x", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::del(&kv, "key_kmg");
    kvdb::set(&kv, "key_xc", "value_y");
    kvdb::del(&kv, "key_j");
    kvdb::del(&kv, "key_l");
    kvdb::del(&kv, "key_j");
    kvdb::set(&kv, "key_wit", "value_ik");
    kvdb::del(&kv, "key_rf");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_b", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_nrl", "value_uvf");
    kvdb::set(&kv, "key_j", "value_w");
    kvdb::del(&kv, "key_nrl");
    kvdb::set(&kv, "key_phx", "value_d");
    kvdb::set(&kv, "key_phx", "value_isom");
    kvdb::set(&kv, "key_l", "value_yww");
    kvdb::set(&kv, "key_b", "value_p");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ru", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ki", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    kvdb::set(&kv, "key_nrl", "value_x");
    kvdb::set(&kv, "key_r", "value_s");
    kvdb::set(&kv, "key_phx", "value_t");
    kvdb::set(&kv, "key_xc", "value_a");
    kvdb::set(&kv, "key_oeb", "value_jypf");
    kvdb::set(&kv, "key_kmg", "value_mapl");
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_rf", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }

}


void test2() {
    // close and re-open
    std::cout << "// test2" << std::endl;
    std::string value;
    kvdb::KVDBHandler kv("kvdb_test2.dat");

    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_wit", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_xc", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_oeb", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_xc", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_kmg", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_l", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_rf", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_nrl", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_oeb", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_r", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_r", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_p", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_j", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_x", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_b", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_wit", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ru", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ki", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_vg", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_j", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }

    if (kvdb::KVDB_OK != purge(&kv)) {
        std::cout << "Failed to PURGE" << std::endl;
    }
    // Again!
    if (kvdb::KVDB_OK != purge(&kv)) {
        std::cout << "Failed to PURGE" << std::endl;
    }

}


void test3() {
    // close and re-open
    std::cout << "// test3" << std::endl;
    std::string value;
    kvdb::KVDBHandler kv("kvdb_test2.dat");

    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_p", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_r", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_vg", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_b", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_nrl", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_l", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_b", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_b", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_vg", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_j", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_yk", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_kmg", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_nrl", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_j", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_ki", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_l", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_oeb", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_yk", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_phx", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }
    
    if (kvdb::KVDB_OK == kvdb::get(&kv, "key_x", &value)) {
        std::cout << value << std::endl;
    } else {
        std::cout << "NOT EXISTS" << std::endl;
    }

}


int main(int, char**) {
    test1();
    test2();
    test3();
    return 0;
}
