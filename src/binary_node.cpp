//
// Created by dingrui on 1/17/26.
//

#include "binary_node.h"

#include "express.h"

BinaryNode::BinaryNode(char operate, const Express num1, const Express num2)
    : m_operate(operate), m_left(num1), m_right(num2) {
}

void BinaryNode::print(std::ostream &os) const {
    os << "(" << this->m_left << this->m_operate << this->m_right << ")";
}

int BinaryNode::eval() {
    int num1 = this->m_left.eval();
    int num2 = this->m_right.eval();
    if (this->m_operate == '+') {
        return num1 + num2;
    }
    if (this->m_operate == '-') {
        return num1 - num2;
    }
    if (this->m_operate == '*') {
        return num1 * num2;
    }
    if (this->m_operate == '/' && num2 != 0) {
        return num1 / num2;
    }
    throw "error, cal";
};
