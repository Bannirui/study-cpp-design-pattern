//
// Created by dingrui on 1/19/26.
//

#pragma once

#include <iostream>

class XiaoMi;
class Apple;

class PhoneVisitor {
public:
    virtual void Visit(XiaoMi *p) =0;

    virtual void Visit(Apple *p) =0;

protected:
    PhoneVisitor() = default;
};

class Phone {
public:
    virtual ~Phone() = default;

    virtual void Dial() =0;

    virtual void SendMsg() =0;

    virtual void Hang() =0;

    virtual void RecvMsg() =0;

    virtual void Accept(PhoneVisitor *visitor) =0;

protected:
    Phone() = default;
};

class XiaoMi : public Phone {
public:
    void Dial() override {
        std::cout << "XiaoMi Dial" << std::endl;
    }

    void SendMsg() override {
        std::cout << "XiaoMi SendMsg" << std::endl;
    }

    void Hang() override {
        std::cout << "XiaoMi Hang" << std::endl;
    }

    void RecvMsg() override {
        std::cout << "XiaoMi RecvMsg" << std::endl;
    }

    void Accept(PhoneVisitor *visitor) override {
        visitor->Visit(this);
    }
};

class Apple : public Phone {
public:
    void Dial() override {
        std::cout << "Apple Dial" << std::endl;
    }

    void SendMsg() override {
        std::cout << "Apple SendMsg" << std::endl;
    }

    void Hang() override {
        std::cout << "Apple Hang" << std::endl;
    }

    void RecvMsg() override {
        std::cout << "Apple RecvMsg" << std::endl;
    }

    void Accept(PhoneVisitor *visitor) override {
        visitor->Visit(this);
    }
};

class AConfigure : public PhoneVisitor {
public:
    void Visit(XiaoMi *p) override {
        p->Dial();
        p->Hang();
        p->RecvMsg();
        p->RecvMsg();
    }

    void Visit(Apple *p) override {
        p->Dial();
        p->Hang();
        p->RecvMsg();
        p->RecvMsg();
    }
};
