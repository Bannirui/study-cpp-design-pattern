//
// Created by dingrui on 1/17/26.
//

#include "aop.h"

#include <iostream>

void Hello::say() {
    std::cout << "Hello World!" << std::endl;
}

Proxy::Proxy(IHello *p)
    : m_pHello(p) {
}

Proxy::~Proxy() {
    if (this->m_pHello) {
        delete this->m_pHello;
        this->m_pHello = nullptr;
    }
}

void Proxy::say() {
    std::cout << "BEFORE:" << std::endl;
    this->m_pHello->say();
    std::cout << "AFTER:" << std::endl;
}
