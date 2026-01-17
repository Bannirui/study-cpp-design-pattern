//
// Created by dingrui on 1/17/26.
//

#include "unary_node.h"

UnaryNode::UnaryNode(char sign, const Express num)
    : m_sign(sign), m_num(num) {
}

void UnaryNode::print(std::ostream &os) const {
    os << "(" << this->m_sign << this->m_num << ")";
}

int UnaryNode::eval() {
    if (this->m_sign == '-') {
        return (-1) * this->m_num.eval();
    }
    throw "error, op";
}
