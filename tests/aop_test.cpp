//
// Created by dingrui on 1/17/26.
//

#include "aop.h"

#include <memory>

int main() {
    std::shared_ptr<IHello> p = std::make_shared<Proxy>(new Hello());
    p->say();
    return 0;
}
