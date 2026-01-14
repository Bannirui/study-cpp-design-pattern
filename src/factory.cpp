//
// Created by dingrui on 1/14/26.
//

#include "factory.h"

#include <iostream>

bool ExportTxt::exportData() {
    std::cout << "ExportTxt" << std::endl;
    return true;
}

bool ExportDB::exportData() {
    std::cout << "ExportDB" << std::endl;
    return true;
}

bool ExportOperate::exportData() {
    this->factoryMethod()->exportData();
    return true;
}

ExportApi *ExportTxtOperate::factoryMethod() {
    return new ExportTxt();
}

ExportApi *ExportDBOperate::factoryMethod() {
    return new ExportDB();
}
