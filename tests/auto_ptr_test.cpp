//
// Created by dingrui on 1/17/26.
//

#include "auto_ptr.hpp"

int main() {
    AutoPtr<int> *pPtr = nullptr;
    {
        AutoPtr<int> gPtr;
        {
            AutoPtr<int> p1(new int(10));
            gPtr = p1;
        }
        AutoPtr<int> p2(new int(20));
        gPtr = p2;
        pPtr = &p2;
        std::cout << pPtr << std::endl;
    }
    return 0;
}
