#ifndef ITEMS_H
#define ITEMS_H

#include "product.cpp"

template <typename T>
class inventory
{
protected:
      static vector<T> products;

public:
      void add_item(T& product);
      void remove_item(int id);
      void sort_by_price(bool asc = true);

      T* find_by_id(int id);

      vector<T> search_by_title(string title);
      vector<T>& get_products();

      friend class Admin;
};

// ==============================================================

class Shopping_Cart;

class Cart_Item
{
protected:
      Product* p;
      int quantity;
public:
      Cart_Item(Product* p, int quantity);

      double subtotal() const;

      friend ostream& operator>>(ostream& out, Product* &p);
      friend ostream& operator<<(ostream& out, Shopping_Cart& cart); // this implementation in Shopping_Cart calss

      friend void apply_Discount(Shopping_Cart cart, double discount);

      friend class Shopping_Cart;
      friend class Customer;
};

// ================================================================

class Shopping_Cart
{
protected:
      vector<Cart_Item> items;
public:
      void addItem(Product* p, int quantity);
      void addItem(Cart_Item temp);
      void removeItem(int id);
      void update_Quantity(int id, int qty);
      void sort_by_Price();
      double calculateTotal();

      friend void apply_Discount(Shopping_Cart cart, double discount);

      friend ostream& operator<<(ostream& out, Shopping_Cart& cart);
      Shopping_Cart operator+(Shopping_Cart cart);

      friend class Customer;
};

// ================================================================

template<class T>
vector<T> inventory<T>::products;

#endif //ITEMS_H
