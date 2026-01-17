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

    /**
     *          +
     *        /   \
     *       a     b
     * a+b
     * @param opend operator, +, -, *, /
     * @param num1 the left
     * @param num2 the right
     */
    BinaryNode(char operate, const Express num1, const Express num2);

    ~BinaryNode() = default;

private:
    void print(std::ostream &os) const override;

    int eval() override;

private:
    /**
     *
     *          +
     *        /   \
     *       a     b
     * a+b
     */
    // operator, +, -, *, /
    char m_operate;
    // the binary tree, left child
    class Express m_left;
    // the binary tree, right child
    class Express m_right;
};
