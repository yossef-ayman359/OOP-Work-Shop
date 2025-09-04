#include "Users.h"

int User::next_id = 165;

// =========================== Admin ===========================

ostream& operator<<(ostream& out, User* u)
{
  u->display(out);
  return out;
}

void Admin::display(ostream& out) const
{
  out << "User name: " << name << "\nUser Id: " << User_id << "\nemail: " << email << endl;
  out << "\t\tInventory Products:\n";
  for (auto* it : inventory<Product*>::products)
    out << it << endl;
}

void Admin::add_Product(Product* p)
{
  inventory<Product*>::products.push_back(p);
}

void Admin::edit_Product(int Id, double price, int qty)
{
  for (auto it : inventory<Product*>::products)
  {
      if (it->get_id() == Id)
      {
          it->set_price(price);
          it->set_quantity(qty);
      }
  }
}

void Admin::remove_Product(int Id)
{
  for(auto it=inventory<Product*>::products.begin(); it != inventory<Product*>::products.end(); ++it)
  {
    if ((*it)->get_id() == Id)
    {
      inventory<Product*>::products.erase(it);
      --it;
    }
  }
}

// void Admin::updats_Stock(int Id, int qty){}  // I don't need this

string Admin::view_Reports()
{
  string s = "\n==============================================\n", rep("");
  rep += "\n================ Inventory Report ================\n";
  rep += "Total Products: " + to_string(inventory<Product*>::products.size());
  // for (auto* it : inventory<Product*>::products)
  // {
  //   if (it->get_quantity() < 6)
  //     {
  //         rep += "\nProduct type: " + it->get_type() + "\nProduct title: " + it->get_title()
  //             + "\nProduct id: " + to_string( it->get_id()) + "\nProduct quantity: " + to_string(it->get_quantity()) + endl;
  //     }
  // }

  rep += s;

  for (auto* it : inventory<Product*>::products)
  {
      if (it->get_quantity() <= 5 && it->get_quantity() != -(1e9))
      {
        rep += it->get_title() + " [ " + to_string(it->get_id()) + " ] " + " (only " + to_string(it->get_quantity()) + " left).\n";
      }
  }
  return rep;
}

istream& operator>>(istream &in, Admin& A)
{
  cout << "Enter Admin Data: \tName & Id & Email & Password\n";
  in >> A.name >> A.User_id >> A.email >> A.password;
  return in;
}

ostream& operator<<(ostream& out, Admin A)
{
  A.display(out);
  return out;
}

// ======================== Customer ===========================

void Customer::display(ostream &out) const
{
  out << "Customer name: " << name << "\nCustomer email: " << email <<
      "\nCustomer id: " << User_id << "\n\t\tCart items\n";

  for (auto it : cart.items)
  {
    it.p->display(out);
    out << "Quantity you need: " << it.quantity << endl;
    out << "===============================\n";
  }

}

void Customer::add_to_cart(Product* p, int quantity)  { cart.addItem(p, quantity); }

void Customer::add_to_cart(Cart_Item temp)  { cart.addItem(temp); }

void Customer::view_Orders()
{
  for (auto it : orders)
  {
    cout << it;
  }
} // use Order operator <<

void Customer::check_out(Payment* p)
{
    for(auto it : this->orders)
    {
        for (auto i : (it.sc).items)
        {
            if (i.p->get_quantity() != -(1e9))
            {
                i.p->set_quantity(i.quantity);
            }
        }
      it.status = "Pending";
    }

}

ostream& operator<<(ostream &out, Customer u)
{
  u.display(out);
  return out;
}

// ========================= Order ==========================

Order::Order() :customer_id(000), total_amount(0), status(""), date("0-0-0000") { order_id = next_id++; }

Order::Order(int customer_id, double total_amount, string status, string date)
: customer_id(customer_id), total_amount(total_amount), status(status), date(date)
{
  order_id = next_id++;
  cout << "You don't have Shopping Cart";
}

Order::Order(int customer_id, double total_amount, string status, string date, Shopping_Cart s_c)
: customer_id(customer_id), total_amount(total_amount), status(status), date(date), sc(s_c)
{ order_id = next_id++; }

void Order::update_status(string new_status) { status = new_status; }

void print_invoice(Order& ord, Customer& ctr)
{
  cout << "\n================= INVOICE =================\n"
       << "Order Id: " << ord.order_id << '\n'
       << "Date: " << ord.date << '\n'
       << "Status: " << ord.status << '\n'
       << "-----------------------------------------------\n";

  cout << "\t\tCustomer detalis:\n" << ctr
       << "-----------------------------------------------\n";

  cout << "Total = " << ctr.get_cart().calculateTotal()
       << "\n-----------------------------------------------\n"
       << "===========================================\n";

}

istream& operator>>(istream& in, Order& order)
{
  cout << "Enter customer id & total amount & status & date.\n";
  in >> order.customer_id >> order.total_amount >> order.status >> order.date;
  return in;
}

ostream& operator<<(ostream& out, Order order)
{
  out << "\nOrder dealis:\n";
  out << "Order Id: " << order.order_id << '\n'
      << "Date: " << order.date << '\n'
      << "Status: " << order.status << '\n'
      << "-----------------------------------------------\n";
  return out;
}