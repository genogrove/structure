#include <genogrove/structure/node.hpp>

namespace genogrove::structure {
    node::node(int order) : order(order), keys{}, children{}, parent{nullptr}, next{nullptr}, is_leaf{false} {}

    // getter & setter
    template<typename key_type>
    void node::insert_key(key<key_type>& key1) {
        int i = 0;
        while(i < this->keys.size() && key.)


    }

}



