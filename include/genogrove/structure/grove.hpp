/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */
#ifndef STRUCTURE_GROVE_HPP
#define STRUCTURE_GROVE_HPP

// standard
#include <unordered_map>

// genogrove
#include <genogrove/utility/ranges.hpp>
#include <genogrove/structure/node.hpp>

namespace ggu = genogrove::utility;

namespace genogrove::structure {
    template<typename key_type>
    class grove {
    public:
        grove(int order) : order(order), root_nodes(), rightmost_nodes() {}
        grove() : order(3), root_nodes(), rightmost_nodes() {}
        ~grove() {}

        /*
         * @brief returns the order of the grove
         */
        int get_order();

        /*
         * @brief sets the order of the grove
         */
        void set_order(int k);

        /*
         * @brief return map with root nodes in the grove
         */
        std::unordered_map<std::string, node<key_type>*> get_root_nodes();

        /*
         * @brief sets the map with root nodes in the grove
         */
        void set_root_nodes(std::unordered_map<std::string, node<key_type>*> root_nodes);

        /*
         * @brief returns the rightmost node in the grove (for easy access)
         * @param The chromosome the grove is associated with
         */
        node<key_type>* get_rightmost_node(std::string key);

        /*
         * @brief sets the rightmode node in the grove (for easy access)
         * @param The key the grove is associated with
         * @param The rightmost node in the grove
         */
        void set_rightmost_node(std::string key, node<key_type>* node);

        /*
         * @brief get the root node of the grove for a given key
         * @param The key associated with the root node (of the grove)
         */
        node<key_type>* get_root(std::string key);

        /*
         * @brief
         */
        node<key_type>* insert_root(std::string key);

        /*
         * @brief inserts a data point into the grove
         * @param The key associated with the data point
         * @param The type of the key to be inserted
         * @param The data point
         */
        template<typename data_type>
        void insert_data(std::string index, key_type ktype, data_type dtype) {
            key<key_type> key(ktype, dtype);
            insert(key, key);
        }

        /*
         * @brief inserts a new key elements into the grove
         */
        void insert(std::string index, key<key_type>& key);

        void insert_iter(node<key_type>* node, key<key_type>& key);

        void split_node(node<key_type>* parent, int index);

    private:
        int order;
        std::unordered_map<std::string, node<key_type>*> root_nodes;
        std::unordered_map<std::string, node<key_type>*> rightmost_nodes;

    };

}


#endif //STRUCTURE_GROVE_HPP
