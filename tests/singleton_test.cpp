//
// Created by dingrui on 1/14/26.
//
#include <iostream>

#include "singleton.h"

int main() {
    Singleton *p1 = Singleton::get_instance();
    Singleton *p2 = Singleton::get_instance();
    std::cout << "p1=" << p1 << " ,p2=" << p2 << std::endl;
    return 0;
}
