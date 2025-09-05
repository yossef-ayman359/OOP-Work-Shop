#include "shop.h"

Shop::Shop(){}

void Shop::register_customer(User* u)
{
    users[u->get_id()] = u;
}

void Shop::login(int user_id)
{
    if (users.find(user_id) == users.end()) { cout << "You are not registered.\n"; return; }

    cout << "Hi, " << users[user_id]->get_name() << " Successful registration.\n";
}

void Shop::add_item(Product* i)
{
    items.add_item(i);
}

void Shop::add_order(Order ord)
{
    orders.push_back(ord);
}

void Shop::checkout_customer(int user_id, Order o)
{
    for (auto order = orders.begin(); order != orders.end(); ++order)
    {
          if (order->get_customer_id() == user_id && order->get_order_id() == o.get_order_id())
          {
            orders.erase(order);
            --order;
          }
    }
}

void Shop::search_items(string keyword)
{
    vector<Product*> products = items.get_products();
    for (auto& item : products)
    {
        if (item->get_title() != keyword) { continue; }
        cout << item;
    }
}

double Shop::generate_sales_report()
{
    return accumulate(orders.begin(), orders.end(), 0.0, [] (double total, Shopping_Cart x) {return total + x.calculateTotal(); } );
}