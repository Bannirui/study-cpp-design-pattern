//
// Created by dingrui on 1/14/26.
//

#pragma once

#include <string>
#include <functional>
#include <iostream>
#include <map>
#include <memory>

template<class T>
class IocContainer {
public:
    IocContainer() = default;

    ~IocContainer() = default;

    template<class Drived>
    void RegisterType(const std::string &strKey) {
        std::function<T*()> creator = []() { return new Drived(); };
        RegisterType(strKey, creator);
    }

    T *Resolve(const std::string &strKey) {
        if (m_createMap.find(strKey) == m_createMap.end()) { return nullptr; }
        std::function<T*()> creator = m_createMap[strKey];
        return creator();
    }

    std::shared_ptr<T> ResolveShard(const std::string &strKey) {
        T *ptr = Resolve(strKey);
        return std::shared_ptr<T>(ptr);
    }

private:
    void RegisterType(const std::string &strKey, std::function<T*()> creator) {
        if (m_createMap.find(strKey) != m_createMap.end()) {
            throw std::invalid_argument("Key already exists");
        }
        m_createMap.emplace(strKey, creator);
    }

private:
    std::map<std::string, std::function<T*()> > m_createMap;
};

struct ICar {
    virtual ~ICar() = default;

    virtual void test() const =0;
};

struct Bus : ICar {
    Bus() = default;

    void test() const override {
        std::cout << "Bus" << std::endl;
    };
};

struct Track : ICar {
    Track() = default;

    void test() const override {
        std::cout << "Track" << std::endl;
    };
};
