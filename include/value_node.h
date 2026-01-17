//
// Created by dingrui on 1/17/26.
//

#pragma once

#include "express_node.h"

class Express;

class ValueNode : public ExpressNode {
public:
    friend class Express;

    ValueNode(int val) : m_val(val) {
    };

    ~ValueNode() override = default;

protected:
    void print(std::ostream &os) const override;

    int eval() override {
        return this->m_val;
    };

private:
    int m_val;
};
