//
// Created by dingrui on 1/17/26.
//

#pragma once

#include "express_node.h"
#include "express.h"

class UnaryNode : public ExpressNode {
public:
    friend class Express;

    UnaryNode(char opend, const Express left);

    ~UnaryNode() override = default;

private:
    void print(std::ostream &os) const override;

    int eval() override;

private:
    char m_opend;
    class Express m_left;
};
