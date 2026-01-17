//
// Created by dingrui on 1/17/26.
//
#include "decorator.h"

#include <iostream>

int main() {
    Beverage *p1 = new Expresso;
    std::cout << p1->get_msg() << ", price=" << p1->cost() << std::endl;

    Beverage *p2 = new Mocha;
    p2 = new Soy(p2);
    p2 = new Soy(p2);
    std::cout << p2->get_msg() << ", price=" << p2->cost() << std::endl;
    return 0;
}
