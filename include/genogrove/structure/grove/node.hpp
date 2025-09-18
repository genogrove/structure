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
#include "genogrove/data_type/key.hpp"
#include "genogrove/data_type/interval.hpp"

namespace gdt = genogrove::data_type;

namespace genogrove::structure {
    template <typename key_type>
    class node {
        public:
            node(int order) :
                order(order),
                keys{},
                children{},
                parent{nullptr},
                next{nullptr},
                is_leaf{false} {}
            ~node();

            // getter & setter
            int get_order() {
                return this->order;
            }
            void set_order(int k) {
                this->order = k;
            }
            std::vector<gdt::key<key_type>>& get_keys() {
                return this->keys;
            }
            void set_keys(std::vector<gdt::key<key_type>> keys) {
                this->keys = keys;
            }
            std::vector<node*>& get_children() {
                return this->children;
            }
            void set_children(std::vector<node*> children) {
                this->children = children;
            }
            node* get_parent() {
                return this->parent;
            }
            void set_parent(node* parent) {
                this->parent = parent;
            }
            void set_next(node* next) {
                this->next = next;
            }
            node* get_next() {
                return this->next;
            }
            void set_is_leaf(bool is_leaf) {
                this->is_leaf = is_leaf;
            }
            bool get_is_leaf() {
                return this->is_leaf;
            }

            void insert_key(gdt::key<key_type>& key1) {
                int i = 0;
                while(i < this->keys.size() && key1.get_value() > this->keys[i].get_value()) { i++; }
                this->keys.insert(this->keys.begin() + i, key1);
            }
            void insert_key(gdt::key<key_type>& key1, int index) {
                this->keys.insert(this->keys.begin() + index, key1);
            }

            key_type calc_parent_key() {
                // create vector of reference intervals
                std::vector<key_type> values = {};
                for (int i = 0; i < this->keys.size(); i++) {
                    values.push_back(this->keys[i].get_value());
                }
                return key_type::aggregate(values);
            }

            void add_child(node* child, int index) {
                this->children.insert(this->children.begin() + index, child);
            }
            node* get_child(int index) { return this->children[index]; }

            /*
             *
             */
            void serialize(std::ostream& os);
            static node* deserialize(std::istream& is, int order);

            void print_keys(std::ostream& os, std::string sep="\t");


        private:
            int order;
            std::vector<gdt::key<key_type>> keys;
            std::vector<node*> children;
            node* parent;
            node* next;
            bool is_leaf;
    };
}

#endif //GENOGROVE_STRUCTURE_NODE_HPP
