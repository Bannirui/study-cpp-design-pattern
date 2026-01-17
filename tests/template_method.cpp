//
// Created by dingrui on 1/18/26.
//

#include "template_method.h"

int main() {
    MakeOrder *a = new AOrder;
    a->Make();

    MakeOrder *b = new BOrder;
    b->Make();

    delete a;
    delete b;
    return 0;
}
