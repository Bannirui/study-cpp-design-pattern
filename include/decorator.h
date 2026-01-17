//
// Created by dingrui on 1/17/26.
//

#pragma once

#include <string>

class Beverage {
public:
    virtual std::string get_msg() =0;

    virtual double cost() =0;

protected:
    Beverage() = default;

    Beverage(std::string msg) : m_msg(msg) {
    };
    std::string m_msg;
};

class CondimentDecorator : public Beverage {
public:
    virtual std::string get_msg() =0;

protected:
    CondimentDecorator() = default;
};

// decorator1
class Soy : public CondimentDecorator {
public:
    Soy(Beverage *beverage) : m_beverage(beverage) {
    };

    std::string get_msg() override { return this->m_beverage->get_msg() + "===>soy"; };

    double cost() override {
        return this->m_beverage->cost() + 0.1;
    };

private:
    Beverage *m_beverage;
};

// decorator2
class Milk : public CondimentDecorator {
public:
    Milk(Beverage *beverage) : m_beverage(beverage) {
    };

    std::string get_msg() override { return this->m_beverage->get_msg() + "===>milk"; };

    double cost() override { return this->m_beverage->cost() + 5.0; };

private:
    Beverage *m_beverage;
};

class Lattee : public Beverage {
public:
    Lattee() : Beverage("Lattee") {
    };

    std::string get_msg() override { return this->Beverage::m_msg; };

    double cost() override { return 5; };
};

class Expresso : public Beverage {
public:
    Expresso() : Beverage("Expresso") {
    };

    std::string get_msg() override {
        return this->Beverage::m_msg;
    };

    double cost() override {
        return 14;
    };
};

class Mocha : public Beverage {
public:
    Mocha() : Beverage("Mocha") {
    };

    std::string get_msg() override {
        return this->Beverage::m_msg;
    };

    double cost() override {
        return 15;
    };
};
