//
// Created by dingrui on 1/17/26.
//

#pragma once

#include <iostream>

class ExpressNode;

class Express {
public:
    Express(int val);

    Express(char op, const Express express);

    Express(char op, const Express express1, const Express express2);

    Express(const Express &other);

    Express &operator=(const Express &other);

    ~Express();

    friend std::ostream &operator<<(std::ostream &os, const Express &express);

    int eval() const;

private:
    class ExpressNode *p;
};
