//
// Created by dingrui on 1/16/26.
//

#include "prototype.h"

int main() {
    HomeOrder *pHome = new HomeOrder();
    pHome->set_order_num(512);
    pHome->set_customer_name("ding");
    pHome->set_product_id("1");

    OrderBiz orderBiz;
    orderBiz.saveOrder(pHome);
    return 0;
}
