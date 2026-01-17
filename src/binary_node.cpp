//
// Created by dingrui on 1/17/26.
//

#include "binary_node.h"

#include "express.h"

BinaryNode::BinaryNode(char opend, const Express left, const Express right)
    : m_opend(opend), m_left(left), m_right(right) {
}

void BinaryNode::print(std::ostream &os) const {
    os << "(" << this->m_left << this->m_opend << this->m_right << ")";
}

int BinaryNode::eval() {
    int ret1 = this->m_left.eval();
    int ret2 = this->m_right.eval();
    if (this->m_opend == '+') {
        return ret1 + ret2;
    }
    if (this->m_opend == '-') {
        return ret1 - ret2;
    }
    if (this->m_opend == '*') {
        return ret1 * ret2;
    }
    if (this->m_opend == '/' && ret2 != 0) {
        return ret1 / ret2;
    }
    throw "error, cal";
};
