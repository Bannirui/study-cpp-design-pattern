//
// Created by dingrui on 1/19/26.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>

class Context {
public:
    Context() : m_value(0), m_operator('\0') {
    }

    int m_value;
    char m_operator;
};

class IExpress {
public:
    virtual void Eval(Context *ctx) =0;

protected:
    IExpress() = default;
};

// operator, + -
class Operator : public IExpress {
public:
    Operator(char op) : m_operator(op) {
    }

    void Eval(Context *ctx) override {
        ctx->m_operator = this->m_operator;
    }

private:
    char m_operator;
};

// number
class Operand : public IExpress {
public:
    Operand(int num) : m_num(num) {
    }

    void Eval(Context *ctx) override {
        switch (ctx->m_operator) {
            case '\0': ctx->m_value = this->m_num;
                break;
            case '+': ctx->m_value += this->m_num;
                break;
            case '-': ctx->m_value -= this->m_num;
                break;
            case '*': ctx->m_value *= this->m_num;
                break;
            case '/': ctx->m_value /= this->m_num;
                break;
            default:
                break;
        }
    }

private:
    int m_num;
};

class Calculator {
public:
    int Cal(std::string express) {
        Context *ctx = new Context();
        std::vector<IExpress *> tree;
        for (int i = 0, n = express.size(); i < n; ++i) {
            if (express[i] == '+' || express[i] == '-') {
                tree.push_back(new Operator(express[i]));
            } else {
                tree.push_back(new Operand((int) (express[i] - '0')));
            }
        }
        for (auto &x: tree) {
            x->Eval(ctx);
        }
        return ctx->m_value;
    }
};
