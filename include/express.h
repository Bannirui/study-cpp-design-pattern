//
// Created by dingrui on 1/17/26.
//

#pragma once

#include <iostream>

class ExpressNode;

class Express {
public:
    /**
     * represent a unsigned num, like 4
     */
    Express(int val);

    /**
     * represent a signed num, like -5
     * @param operate + - * /
     * @param num
     */
    Express(char operate, const Express num);

    /**
     * num1 + num2
     * @param operate +, -, *, /
     * @param num1
     * @param num2
     */
    Express(char operate, const Express num1, const Express num2);

    Express(const Express &other);

    Express &operator=(const Express &other);

    ~Express();

    friend std::ostream &operator<<(std::ostream &os, const Express &express);

    int eval() const;

private:
    class ExpressNode *p;
};
