//
// Created by dingrui on 1/18/26.
//

#pragma once

#include <iostream>

class IOS {
public:
    IOS() = default;

    virtual ~IOS() = default;

    virtual void Run() =0;
};

class CWindows : public IOS {
public:
    ~CWindows() override = default;

    void Run() override {
        std::cout << "windows running..." << std::endl;
    };
};

class CLinux : public IOS {
public:
    ~CLinux() override = default;

    void Run() override {
        std::cout << "linux running..." << std::endl;
    };
};

class IComputer {
public:
    virtual void Install(IOS *pOs) =0;

protected:
    IComputer() = default;
};

class CLenvo : public IComputer {
public:
    void Install(IOS *pOs) override {
        std::cout << "Lenvo install system." << std::endl;
        pOs->Run();
    };
};

class CDell : public IComputer {
public:
    void Install(IOS *pOs) override {
        std::cout << "Delll install system." << std::endl;
        pOs->Run();
    };
};
