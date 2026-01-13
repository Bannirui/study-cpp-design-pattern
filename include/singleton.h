//
// Created by dingrui on 1/14/26.
//

#pragma once

#include <string>
#include <mutex>

class Singleton {
public:
    static Singleton *get_instance();

private:
    // in cpp, constructor is not safe when concurrent
    // lazy mode, constructor for multiple thread
    Singleton();

private:
    static Singleton *m_instance;
    static std::mutex m_mutex;
    static std::string DEFAULT_KEY;
};
