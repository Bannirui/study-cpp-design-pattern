//
// Created by dingrui on 1/14/26.
//

#pragma once

#include <iostream>

class ExportApi {
public:
    virtual bool exportData() =0;

protected:
    ExportApi() = default;
};

class ExportTxt : public ExportApi {
public:
    bool exportData() override {
        std::cout << "ExportTxt" << std::endl;
        return true;
    }
};

class ExportDB : public ExportApi {
public:
    bool exportData() override {
        std::cout << "ExportDB" << std::endl;
        return true;
    }
};

class ExportOperate {
public:
    bool exportData() {
        this->factoryMethod()->exportData();
        return true;
    }

protected:
    ExportOperate() = default;

    virtual ExportApi *factoryMethod() =0;
};

class ExportTxtOperate : public ExportOperate {
protected:
    ExportApi *factoryMethod() override {
        return new ExportTxt();
    }
};

class ExportDBOperate : public ExportOperate {
protected:
    ExportApi *factoryMethod() override {
        return new ExportDB();
    }
};
