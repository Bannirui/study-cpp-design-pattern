//
// Created by dingrui on 1/19/26.
//

#include "iterator.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
