#include <genogrove/structure/node.hpp>

namespace genogrove::structure {
    template<typename key_type>
    node<key_type>::node(int order) : order(order), keys{}, children{}, parent{nullptr}, next{nullptr}, is_leaf{false} {}
}



