//
// Created by dingrui on 1/16/26.
//

#include "adapter.h"

#include <iostream>

int main() {
    TwoPhaseOutlet *x = new OutletConverter;
    x->doPlug();

    std::cout << "---" << std::endl;

    TwoPhaseOutlet *y = new OutletObjConvert(new ThreePhaseOutlet);
    y->doPlug();
    return 0;
}
