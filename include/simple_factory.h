//
// Created by dingrui on 1/13/26.
//

#pragma once

// interface
class Api {
public:
    virtual void test() =0;

protected:
    Api() = default;
};

class ImplOne : public Api {
public:
    void test() override;
};

class ImplTwo : public Api {
public:
    void test() override;
};


class Factory {
public:
    static Api *createApi();
};
