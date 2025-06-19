/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */
#ifndef GENOGROVE_STRUCTURE_NODE_HPP
#define GENOGROVE_STRUCTURE_NODE_HPP

// standard
#include <vector>

// genogrove
#include <genogrove/structure/key.hpp>

namespace genogrove::structure {
    template <typename key_type>
    class node {
        public:
            node(int k);
            ~node();

            // getter & setter
            int get_order();
            void set_order(int k);
            std::vector<node*> get_keys();
            void set_keys(std::vector<node*> keys);
            std::vector<node*>& get_children();
            void set_children(std::vector<node*> children);
            node* get_parent();
            void set_parent(node* parent);
            void set_next(node* next);
            node* get_next();
            void set_is_leaf(bool is_leaf);
            bool get_is_leaf();

            void insert_key(key<key_type>& key1);

            void insert_key(key<key_type>& key1, int index);

            key_type calc_parent_key(key<key_type>& key1);

            void add_child(node* child, int index);
            node* get_child(int index);

            /*
             *
             */
            void serialize(std::ostream& os);
            static node* deserialize(std::istream& is, int order);

            void print_keys(std::ostream& os, std::string sep="\t");


        private:
            int order;
            std::vector<key_type> keys;
            std::vector<node*> children;
            node* parent;
            node* next;
            bool is_leaf;
    };
}

#endif //GENOGROVE_STRUCTURE_NODE_HPP
