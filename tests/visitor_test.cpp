//
// Created by dingrui on 1/19/26.
//

#include "visitor.h"

int main() {
    PhoneVisitor *visitor = new AConfigure;
    XiaoMi *xiaomi = new XiaoMi();
    Apple *apple = new Apple();
    xiaomi->Accept(visitor);
    apple->Accept(visitor);
    return 0;
}
