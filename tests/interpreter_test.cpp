//
// Created by dingrui on 1/19/26.
//

#include "interpreter.h"

int main() {
    Calculator calc;
    std::string express = "1+4-2";
    std::cout << express << "=" << calc.Cal(express) << std::endl;
    return 0;
}
