#ifndef USERS_H
#define USERS_H

#include "payment.cpp"

class Customer;
class Admin;

class Order
{
protected:
    static int next_id;
    int order_id, customer_id;
    double total_amount;
    string status, date;
    Shopping_Cart sc;
public:
    Order();
    Order(int customer_id, double total_amount, string stats, string date);
    Order(int customer_id, double total_amount, string stats, string date, Shopping_Cart s_c);

    void update_status(string new_status);
    int get_customer_id() {return customer_id;}
    int get_order_id() {return order_id;}
    Shopping_Cart get_shop_cart() {return sc;}

    friend void print_invoice(Order& ord, Customer& ctr);
    friend istream& operator>>(istream& in, Order& order);
    friend ostream& operator<<(ostream& out, Order order);


    friend class Customer;

};

// =========================== Admin ===========================

class User
{
protected:
      static int next_id;
      int User_id;
      string name, email, password;

public:
     User() : name("Admin"), email("nksn"), password("kdnkdnck4") {User_id = next_id++;}
     virtual void display(ostream& out) const = 0;

    virtual string get_name()   {return name;}
    virtual string get_email()  {return email;}
    virtual int get_id()        {return User_id;}

     friend ostream& operator<<(ostream& out, User* u);
     friend void print_Invoice(Order& ord, Customer& ctr);
}
;
// ========================= Customer ==========================

class Admin : public User
{
public:
  void display(ostream& out) const;

  void add_Product(Product* p);
  void edit_Product(int Id, double price=0.0, int qty=0);
  void remove_Product(int Id);
  // void update_Stock(int Id, int qty);  // I don't need this
  string view_Reports();


  friend istream& operator>>(istream& in, Admin& A);
  friend ostream& operator<<(ostream& out, Admin A);
};


// ========================= Customer ==========================

class Customer : public User
{
protected:
    string address;
    Shopping_Cart cart;
    vector<Order> orders;
public:
    void display(ostream &out) const override;
    void add_to_cart(Product* p, int quantity);
    void add_to_cart(Cart_Item temp);
    void view_Orders();
    void check_out(Payment* p);

    Shopping_Cart get_cart() { return cart;}

    friend ostream& operator<<(ostream& out, Customer u);
    friend void print_Invoice(Order& ord, Customer& ctr); // this implementation in Order class

    friend class Credit_Card_Payment;
};



int Order::next_id = 1;

#endif //USERS_H
