//
// Created by dingrui on 1/16/26.
//

#include "adapter.h"

#include <iostream>

void ThreePhaseOutlet::doThreePhaseOutlet() {
    std::cout << "three" << std::endl;
}

void OutletConverter::doPlug() {
    this->doConvert();
    this->ThreePhaseOutlet::doThreePhaseOutlet();
}

void OutletConverter::doConvert() {
    std::cout << "convert" << std::endl;
}

OutletObjConvert::OutletObjConvert(ThreePhaseOutlet *p) : m_outlet(p) {
}

void OutletObjConvert::doPlug() {
    this->doConvert();
    this->m_outlet->doThreePhaseOutlet();
}

void OutletObjConvert::doConvert() {
    std::cout << "convert" << std::endl;
}
