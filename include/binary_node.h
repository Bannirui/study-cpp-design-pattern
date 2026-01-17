//
// Created by dingrui on 1/17/26.
//

#pragma once

#include "express.h"
#include "express_node.h"

class Express;

class BinaryNode : public ExpressNode {
public:
    friend class Express;

    BinaryNode(char opend, const Express left, const Express right);

    ~BinaryNode() = default;

private:
    void print(std::ostream &os) const override;

    int eval() override;

private:
    char m_opend;
    class Express m_left;
    class Express m_right;
};
