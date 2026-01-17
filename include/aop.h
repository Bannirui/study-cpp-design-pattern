//
// Created by dingrui on 1/17/26.
//

#pragma once

// interface
class IHello {
public:
    virtual ~IHello() = default;

    virtual void say() =0;

protected:
    IHello() = default;
};

class Hello : public IHello {
public:
    void say() override;
};

class Proxy : public IHello {
public:
    explicit Proxy(IHello *p);

    ~Proxy() override;

    void say() final;

private:
    IHello *m_pHello;
};
