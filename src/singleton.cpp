//
// Created by dingrui on 1/14/26.
//

#include "singleton.h"

#include <iostream>

// lazy mode
Singleton *Singleton::m_instance = nullptr;
std::mutex Singleton::m_mutex;

Singleton *Singleton::get_instance() {
    if (!m_instance) {
        std::lock_guard<std::mutex> lock(m_mutex);
        // double check
        if (!m_instance) {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}

Singleton::Singleton() {
    std::cout << "Singleton constructor" << std::endl;
}
