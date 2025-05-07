/*
 * SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

#ifndef GENOGROVE_STRUCTURE_KEY_HPP
#define GENOGROVE_STRUCTURE_KEY_HPP

// standard
#include <vector>

// genogrove
#include <genogrove/data_type/any_type.hpp>

namespace ggt = genogrove::data_type;

namespace genogrove::structure {
    /*
     * @brief the key class
     * @details the key class is used to identify a node in the graph.
     */
    template<typename key_type>
    class key {
        public:
            /*
             * @brief Default constructor
             */
            key();
            key(const key&);

        private:
            key_type value;
            std::shared_ptr<ggt::any_base> data;
            key* single_link;
            std::vector<key*> multi_link;
    };
}

#endif //GENOGROVE_STRUCTURE_KEY_HPP
