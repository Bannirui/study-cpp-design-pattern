//
// Created by dingrui on 1/17/26.
//

#include "value_node.h"

#include "express.h"

void ValueNode::print(std::ostream &os) const {
    os << this->m_val;
};
