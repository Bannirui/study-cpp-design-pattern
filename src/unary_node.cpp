//
// Created by dingrui on 1/17/26.
//

#include "unary_node.h"

UnaryNode::UnaryNode(char opend, const Express left)
    : m_opend(opend), m_left(left) {
}

void UnaryNode::print(std::ostream &os) const {
    os << "(" << this->m_opend << this->m_left << ")";
}

int UnaryNode::eval() {
    if (this->m_opend == '-') {
        return (-1) * this->m_left.eval();
    }
    throw "error, op";
}
