//
// Created by dingrui on 1/17/26.
//

#pragma once

#include "express_node.h"
#include "express.h"

class UnaryNode : public ExpressNode {
public:
    friend class Express;

    /**
     * represent a signed num, like -5
     * @param sign + -
     * @param num
     */
    UnaryNode(char sign, const Express num);

    ~UnaryNode() override = default;

private:
    void print(std::ostream &os) const override;

    int eval() override;

private:
    // represent a sign num, like -5
    char m_sign;
    class Express m_num;
};
