//
// Created by dingrui on 1/17/26.
//

#include "express.h"

#include "binary_node.h"
#include "unary_node.h"
#include "value_node.h"

Express::Express(int val) {
    this->p = new ValueNode(val);
}

Express::Express(char operate, const Express num) {
    this->p = new UnaryNode(operate, num);
};

Express::Express(char operate, const Express num1, const Express num2) {
    this->p = new BinaryNode(operate, num1, num2);
};

Express::Express(const Express &other) {
    this->p = other.p;
    this->p->set_use(this->p->get_use() + 1);
};

Express &Express::operator=(const Express &other) {
    other.p->set_use(other.p->get_use() + 1);
    this->p->set_use(this->p->get_use() - 1);
    if (this->p->get_use() == 0) {
        delete this->p;
    }
    this->p = other.p;
    return *this;
};

Express::~Express() {
    this->p->set_use(this->p->get_use() - 1);
    if (this->p->get_use() == 0) {
        delete this->p;
    }
};

std::ostream &operator<<(std::ostream &os, const Express &express) {
    os << *(express.p);
    return os;
}

int Express::eval() const {
    return this->p->eval();
}
