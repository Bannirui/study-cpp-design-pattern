//
// Created by dingrui on 1/17/26.
//

#pragma once

#include <iostream>

class Express;

class ExpressNode {
public:
    friend class Express;

    int get_use() const {
        return this->m_use;
    };

    void set_use(int u) {
        this->m_use = u;
    };

    friend std::ostream &operator<<(std::ostream &os, const ExpressNode &node) {
        node.print(os);
        return os;
    };

    ExpressNode() : m_use(1) {
    };

    virtual ~ExpressNode() = default;

protected:
    virtual void print(std::ostream &os) const =0;

    virtual int eval() =0;

private:
    int m_use;
};
