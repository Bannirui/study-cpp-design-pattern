//
// Created by dingrui on 1/17/26.
//

#include "express.h"
#include "express_node.h"
#include "value_node.h"
#include "unary_node.h"
#include "binary_node.h"

int main() {
    Express t(3);
    t = Express('+', t, 12);
    std::cout << t << "=" << t.eval() << std::endl;

    Express y('-', 4);
    std::cout << y << "=" << y.eval() << std::endl;

    Express x('*', Express('-', 5), Express('+', 3, 4));
    std::cout << x << "=" << x.eval() << std::endl;
    return 0;
}
