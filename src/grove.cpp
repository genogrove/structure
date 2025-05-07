#include <genogrove/structure/grove.hpp>

namespace genogrove::structure {
    // constructors
    grove::grove(int k) : order(k), root_nodes(), rightmost_nodes() {}
    grove::grove() : order(3), root_nodes(), rightmost_nodes() {}
    grove::~grove() {}

    // getters & setters
    int grove::get_order() { return this->order; }
    void grove::set_order(int k) { this->order = k; }
    std::unordered_map<std::string, node*> grove::get_root_nodes() { return this->root_nodes; }
    void grove::set_root_nodes(std::unordered_map<std::string, node*> root_nodes) { this->root_nodes = root_nodes; }
    node* grove::get_rightmost_node(std::string key) { return this->rightmost_nodes[key]; }
    void grove::set_rightmost_node(std::string key, node* node) { this->rightmost_nodes[key] = node; }

    node* grove::get_root(std::string key) {
        node* root = nullptr;
        // check if the root node is in the map
        if(ggu::ranges::contains(this->root_nodes, key)) {
            root = this->root_nodes[key];
        }
        return root;
    }
}