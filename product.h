#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int id;
    string title;
    string description;
    double price;
    string category;

    static int next_id;
    static double global_discount;

public:
    Product(const string& t, const string& d, double p, const string& c)
        : title(t), description(d), price(p), category(c) {
        id = next_id++;
    }

    virtual ~Product() {}

    virtual void display(ostream& os) const = 0;
    virtual string get_type() const = 0;

    double price_after_discount() const {
        return price * (1.0 - global_discount);
    }

    bool operator==(const Product& other) const {
        return this->id == other.id;
    }

    friend ostream& operator<<(ostream& os, const Product& p) {
        p.display(os);
        return os;
    }

    static void set_global_discount(double d) {
        if (d >= 0 && d <= 1.0) global_discount = d;
    }

    static double get_global_discount() {
        return global_discount;
    }

    int get_id() const { return id; }
    string get_title() const { return title; }
    string get_description() const { return description; }
    double get_price() const { return price; }
    string get_category() const { return category; }
};

int Product::next_id = 1;
double Product::global_discount = 0.0;
