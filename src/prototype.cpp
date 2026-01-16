//
// Created by dingrui on 1/16/26.
//

#include "prototype.h"

#include <iostream>

int HomeOrder::get_order_num() const {
    return this->m_order_cnt;
}

void HomeOrder::set_order_num(int n) {
    this->m_order_cnt = n;
}

std::string HomeOrder::get_order_content() const {
    return "customer name=" + this->m_customer_name + " product id=" + this->m_product_id + " order cnt=" +
           std::to_string(this->m_order_cnt);
}

std::string HomeOrder::get_customer_name() const {
    return this->m_customer_name;
}

void HomeOrder::set_customer_name(std::string customer_name) {
    this->m_customer_name = customer_name;
}

std::string HomeOrder::get_product_id() const {
    return this->m_product_id;
}

void HomeOrder::set_product_id(std::string customer_id) {
    this->m_product_id = customer_id;
}

OrderApi *HomeOrder::cloneOrder() {
    HomeOrder *p = new HomeOrder();
    p->set_customer_name(this->m_customer_name);
    p->set_product_id(this->m_product_id);
    p->set_order_num(this->m_order_cnt);
    return p;
}

int AboardOrder::get_order_num() const {
    return this->m_order_cnt;
}

void AboardOrder::set_order_num(int n) {
    this->m_order_cnt = n;
}

std::string AboardOrder::get_order_content() const {
    return "customer name=" + this->m_customer_name + " product id=" + this->m_product_id + " order cnt=" +
           std::to_string(this->m_order_cnt);
}

std::string AboardOrder::get_customer_name() const {
    return this->m_customer_name;
}

void AboardOrder::set_customer_name(std::string customer_name) {
    this->m_customer_name = customer_name;
}

std::string AboardOrder::get_product_id() const {
    return this->m_product_id;
}

void AboardOrder::set_product_id(std::string customer_id) {
    this->m_product_id = customer_id;
}

OrderApi *AboardOrder::cloneOrder() {
    HomeOrder *p = new HomeOrder();
    p->set_customer_name(this->m_customer_name);
    p->set_product_id(this->m_product_id);
    p->set_order_num(this->m_order_cnt);
    return p;
}

void OrderBiz::saveOrder(OrderApi *pOrder) {
    while (pOrder->get_order_num() > 200) {
        OrderApi *pNewOrder = pOrder->cloneOrder();
        pNewOrder->set_order_num(200);

        pOrder->set_order_num(pOrder->get_order_num() - 200);
        std::cout << "new order is:" << pNewOrder->get_order_content() << std::endl;
    }
    std::cout << "final order is:" << pOrder->get_order_content() << std::endl;
}
