#include <genogrove/structure/node.hpp>

namespace genogrove::structure {
    <typename key_type>
    node<key_type>::node(int order) : order(order), keys{}, children{}, parent{nullptr}, next{nullptr}, is_leaf{false} {}

    // getter & setter


    template<typename key_type>
    void node<key_type>::insert_key(key<key_type>& key1) {
        int i = 0;
        while(i < this->keys.size() && key1.get_value() > this->keys[i].get_value()) { i++; }


    }

}



