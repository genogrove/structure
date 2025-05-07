#include <genogrove/structure/grove.hpp>

namespace genogrove::structure {
    // constructors
    grove::grove(int k) : order(k), root_nodes(), rightmost_nodes() {}
    grove::grove() : order(3), root_nodes(), rightmost_nodes() {}
    grove::~grove() {}

    // getters & setters
    int grove::get_order() { return this->order; }
    void grove::set_order(int k) { this->order = k; }
    std::unordered_map<std::string, Node*> grove::get_root_nodes() { return this->root_nodes; }
    void grove::set_root_nodes(std::unordered_map<std::string, Node*> root_nodes) { this->root_nodes = root_nodes; }
    Node* grove::get_rightmost_node(std::string key) { return this->rightmost_nodes[key]; }
    void grove::set_rightmost_node(std::string key, Node* node) { this->rightmost_nodes[key] = node; }

    Node* grove::get_root(std::string key) {
        Node* root = nullptr;
        // check if the root node is in the map
        if(ggu::contains(this->root_nodes, key)) {
            root = this->root_nodes[key];
        }
        return root;
    }
}