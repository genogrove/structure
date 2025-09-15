/*
* SPDX-License-Indentifier: MIT
 *
 * Copyright (c) 2025 Richard A. Schäfer
 *
 * This file is part of genogrove and is licensed under the terms of the MIT license.
 * See the LICENSE file in the root of the repository for more information.
 */

// Google Test
#include <gtest/gtest.h>

// genogrove
#include <genogrove/data_type/interval.hpp>
#include <genogrove/structure/grove/grove.hpp>

namespace gdt = genogrove::data_type;
namespace gst = genogrove::structure;

TEST(interval_grove_test, interval_creation) {
    gst::grove<gdt::interval> grove(4);
    gdt::interval intvl1{5, 10};
    int value = 10;

    grove.insert_data<int>("index1", intvl1, value);
}