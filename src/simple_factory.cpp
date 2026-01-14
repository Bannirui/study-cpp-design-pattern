//
// Created by dingrui on 1/13/26.
//

#include "simple_factory.h"

#include <iostream>

#include "dyn_obj.h"

void ImplOne::test() {
    std::cout << "ImplOne executing" << std::endl;
}

void ImplTwo::test() {
    std::cout << "ImplTwo executing" << std::endl;
}

// register impl object
REG_CLASS(ImplOne)
REG_CLASS(ImplTwo)

Api *Factory::createApi() {
    std::string name = "ImplOne";
    Api *p = nullptr;
    p = static_cast<Api *>(CObjectFactory::createObject(name));
    return p;
}
