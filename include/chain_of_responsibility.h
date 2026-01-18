//
// Created by dingrui on 1/18/26.
//

#pragma once

#include <iostream>

class Handler {
public:
    void set_next(Handler *handler) {
        this->m_handler = handler;
    }

    virtual void handle(double amount) =0;

    virtual ~Handler() = default;

protected:
    Handler *m_handler;
};

class ProjectManager : public Handler {
public:
    void handle(double amount) override {
        if (amount < 500) {
            std::cout << "Project Manager Received: " << amount << std::endl;
        } else {
            if (this->m_handler) {
                this->m_handler->handle(amount);
            }
        }
    }
};

class DirectorManager : public Handler {
public:
    void handle(double amount) override {
        if (500 <= amount && amount < 1000) {
            std::cout << "Director Manager Received: " << amount << std::endl;
        } else {
            if (this->m_handler) {
                this->m_handler->handle(amount);
            }
        }
    }
};

class CEO : public Handler {
public:
    void handle(double amount) override {
        if (amount >= 1000) {
            std::cout << "CEO Received: " << amount << std::endl;
        } else {
            if (this->m_handler) {
                this->m_handler->handle(amount);
            }
        }
    }
};
