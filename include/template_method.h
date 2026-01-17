//
// Created by dingrui on 1/18/26.
//

#pragma once

#include <iostream>

class MakeOrder {
public:
    virtual ~MakeOrder() = default;

    void Make() {
        this->pre();
        this->startOrder();
        this->post();
    }

protected:
    MakeOrder() = default;

    virtual void pre() =0;

    virtual void startOrder() {
        std::cout << "start ordering" << std::endl;
    };

    virtual void post() =0;
};

class AOrder : public MakeOrder {
    void pre() override {
        std::cout << "A pre ordering" << std::endl;
    }

    void post() override {
        std::cout << "A post ordering" << std::endl;
    }
};

class BOrder : public MakeOrder {
private:
    void pre() override {
        std::cout << "B pre ordering" << std::endl;
    }

    void startOrder() override {
        std::cout << "B start ordering" << std::endl;
    };

    void post() override {
        std::cout << "B post ordering" << std::endl;
    }
};
