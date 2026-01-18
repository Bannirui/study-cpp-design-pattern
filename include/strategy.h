//
// Created by dingrui on 1/18/26.
//

#pragma once

#include <iostream>

// abstract behavior as Object
class QuackBehavior {
public:
    virtual ~QuackBehavior() = default;

    virtual void Quack() =0;

protected:
    QuackBehavior() = default;
};

class Quack1 : public QuackBehavior {
public:
    void Quack() override {
        std::cout << "Quack1" << std::endl;
    };
};

class Quack2 : public QuackBehavior {
public:
    void Quack() override {
        std::cout << "Quack2" << std::endl;
    };
};

class FlyBehavior {
public:
    virtual ~FlyBehavior() = default;

    virtual void Fly() =0;

protected:
    FlyBehavior() = default;
};

class Fly1 : public FlyBehavior {
public:
    void Fly() override {
        std::cout << "Fly1" << std::endl;
    };
};

class Fly2 : public FlyBehavior {
public:
    void Fly() override {
        std::cout << "Fly2" << std::endl;
    };
};

// duck has a quack and a fly object
class Duck {
public:
    virtual void Display() {
        if (this->m_pQuack) {
            this->m_pQuack->Quack();
        }
        if (this->m_pFly) {
            this->m_pFly->Fly();
        }
    }

    void set_quack_behavior(QuackBehavior *ptr) {
        this->m_pQuack = ptr;
    }

    void set_fly_behavior(FlyBehavior *ptr) {
        this->m_pFly = ptr;
    }

protected:
    Duck() = default;

    virtual ~Duck() {
        if (this->m_pQuack) {
            delete this->m_pQuack;
        }
        if (this->m_pFly) {
            delete this->m_pFly;
        }
    }

    QuackBehavior *m_pQuack{nullptr};
    FlyBehavior *m_pFly{nullptr};
};

class DonaladDuck : public Duck {
public:
    DonaladDuck() {
        this->m_pQuack = new Quack1();
    };
};

class RubberDuck : public Duck {
public:
    RubberDuck() {
        this->m_pQuack = new Quack2();
        this->m_pFly = new Fly1();
    }
};
