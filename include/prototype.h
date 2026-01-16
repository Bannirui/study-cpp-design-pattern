//
// Created by dingrui on 1/16/26.
//

#pragma once

#include <string>

class OrderApi {
public:
    virtual int get_order_num() const = 0;

    virtual void set_order_num(int n) = 0;

    virtual std::string get_order_content() const = 0;

    virtual OrderApi *cloneOrder() = 0;

protected:
    OrderApi() = default;
};

class HomeOrder : public OrderApi {
public:
    int get_order_num() const override;

    void set_order_num(int n) override;

    std::string get_order_content() const override;

    std::string get_customer_name() const;

    void set_customer_name(std::string customer_name);

    std::string get_product_id() const;

    void set_product_id(std::string customer_id);

    OrderApi *cloneOrder() override;

private:
    std::string m_customer_name;
    std::string m_product_id;
    int m_order_cnt;
};

class AboardOrder : public OrderApi {
public:
    int get_order_num() const override;

    void set_order_num(int n) override;

    std::string get_order_content() const override;

    std::string get_customer_name() const;

    void set_customer_name(std::string customer_name);

    std::string get_product_id() const;

    void set_product_id(std::string customer_id);

    OrderApi *cloneOrder() override;

private:
    std::string m_customer_name;
    std::string m_product_id;
    int m_order_cnt;
};

class OrderBiz {
public:
    void saveOrder(OrderApi *pOrder);
};
