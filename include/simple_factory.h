//
// Created by dingrui on 1/13/26.
//

#pragma once

#include <string>
#include <iostream>

#include "dyn_obj.h"

class Api {
public:
    virtual void test() =0;

protected:
    Api() = default;
};

class ImplOne : public Api {
public:
    void test() override {
        std::cout << "ImplOne executing" << std::endl;
    }
};

class ImplTwo : public Api {
public:
    void test() override {
        std::cout << "ImplTwo executing" << std::endl;
    }
};

REG_CLASS(ImplOne)
REG_CLASS(ImplTwo)

class Factory {
public:
    static Api *createApi() {
        std::string name = "ImplTwo";
        Api *p = nullptr;
        p = static_cast<Api *>(CObjectFactory::createObject(name));
        return p;
    }
};
