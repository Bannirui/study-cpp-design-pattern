//
// Created by dingrui on 1/14/26.
//

#include "singleton.h"

#include <iostream>
#include <map>

// lazy mode
Singleton *Singleton::m_instance = nullptr;
std::mutex Singleton::m_mutex;
std::string Singleton::DEFAULT_KEY = "ONE";

std::map<std::string, Singleton *> map = std::map<std::string, Singleton *>();

Singleton *Singleton::get_instance() {
    if (map.find(DEFAULT_KEY) != map.end()) {
        return map.at(DEFAULT_KEY);
    }
    if (!m_instance) {
        std::lock_guard<std::mutex> lock(m_mutex);
        // double check
        if (!m_instance) {
            m_instance = new Singleton();
            map[DEFAULT_KEY] = m_instance;
        }
    }
    return m_instance;
}

Singleton::Singleton() {
    m_instance = nullptr;
    std::cout << "Singleton constructor" << std::endl;
}
