#ifndef PRODUCT_H
#define PRODUCT_H

#include "bits/stdc++.h"
using namespace std;

#define endl '\n'

class Product {
protected:
    int id;
    double price;
    string title, description, category;

public:
    static long int next_id;
    static double global_discount;

    Product() = default;
    Product(string& title, string& description, double price, string& category) : title(title), description(description), price(price), category(category)
    {
        id = next_id++;
    }

    virtual ~Product() = default;

    virtual void display(ostream& os) = 0;
    virtual string get_type() = 0;
    virtual double price_after_discount() = 0;


    bool operator==(Product* other)
    {
        return this->id == other->id;
    }

    friend ostream& operator<<(ostream& os, Product* p)
    {
        p->display(os);
        return os;
    }

    static void set_global_discount(double d)
    {
        if (d >= 0 && d <= 100) global_discount = d;
    }

    static double get_global_discount()
    {
        return global_discount;
    }

    virtual int get_id()  { return id; }
    virtual string get_title()  { return title; }
    virtual string get_description()  { return description; }
    virtual double get_price()  { return price; }
    virtual string get_category()  { return category; }
    virtual int get_quantity(){ return -(1e9); } // this for Cart item , if qty > available stock

    virtual void set_quantity(int qty) {return;}; // this for Cart item , if qty > available stock
    virtual void set_price(double price) {this->price += price;}


    friend class Cart_Item;
};

// ========================================================================================================================================================================

class Physical_Product : public Product
{
protected:
    int stock_quantity;
    double weight;

public:
    Physical_Product();
    Physical_Product(string title,  string description, string category, double price, int stock, double weight);

    bool reduce_stock(int qty);
    void increase_stock(int qty);

    void display(ostream& os)  override;
    string get_type()  override;
    double price_after_discount() override;

    int get_quantity() override;
    double get_weight() ;

    void set_quantity(int qty)  override;



    friend istream& operator>>(istream& in, Physical_Product& p);
    friend ostream& operator<<(ostream& out, Physical_Product& p);
    friend class Cart_Item;
};

// ========================================================================================================================================================================

class Digital_Product : public Product
{
protected:
    double file_size_mb;
    string download_url, file_format;

public:
    Digital_Product();
    Digital_Product(string title, string description, string category, string url, string format, double price, double size_mb);

    void display(ostream& os)  override;
    string get_type()  override;
    double price_after_discount() override;
    int get_quantity() override;

    string get_download_url();
    string get_file_format();
    double get_file_size_mb();

    friend istream& operator>>(istream& in, Digital_Product& p);
    friend ostream& operator<<(ostream& out, Digital_Product& p);
};


#endif // PRODUCT_H
