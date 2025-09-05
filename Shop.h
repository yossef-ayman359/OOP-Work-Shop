#ifndef SHOP_H
#define SHOP_H

#include "Users.h"
#include "Users.cpp"

class Shop
{
protected:
    inventory<Product*> items;
    map<int, User*> users;
    vector<Order> orders; // this same Atr in Customer class

public:
    Shop();

    void register_customer(User* u);
    void login(int user_id);
    void add_item(Product* i);
    void add_order(Order ord);
    void checkout_customer(int user_id, Order o);
    void search_items(string keyword);
    double generate_sales_report();
};

#endif //SHOP_H
