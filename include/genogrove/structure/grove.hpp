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
    class grove {
    public:
        grove(int k);
        grove();
        ~grove();

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
        std::unordered_map<std::string, node*> get_root_nodes();

        /*
         * @brief sets the map with root nodes in the grove
         */
        void set_root_nodes(std::unordered_map<std::string, node*> root_nodes);

        /*
         * @brief returns the rightmost node in the grove (for easy access)
         * @param The chromosome the grove is associated with
         */
        node* get_rightmost_node(std::string key);

        /*
         * @brief sets the rightmode node in the grove (for easy access)
         * @param The key the grove is associated with
         * @param The rightmost node in the grove
         */
        void set_rightmost_node(std::string key, node* node);

        /*
         * @brief get the root node of the grove for a given key
         * @param The key associated with the root node (of the grove)
         */
        node* get_root(std::string key);

        /*
         * @brief
         */
        node* insert_root(std::string key);

        /*
         * @brief inserts a data point into the grove
         * @param The key associated with the data point
         * @param The type of the key to be inserted
         * @param The data point
         */
        template<typename key_type, typename data_type>
        void insert_data(std::string index, key_type ktype, data_type dtype) {
            Key key(ktype, dtype);
            insert(key, key);
        }

        /*
         * @brief inserts a new key elements into the grove
         */
        void insert(std::string index, Key& key);

        void insert_iter(node* node, Key& key);

        void split_node(node* parent, int index);

    private:
        int order;
        std::unordered_map<std::string, node*> root_nodes;
        std::unordered_map<std::string, node*> rightmost_nodes;

    };

}


#endif //STRUCTURE_GROVE_HPP
