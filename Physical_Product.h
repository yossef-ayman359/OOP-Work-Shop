#include "product.h"

class physical_product : public Product {
private:
    int stock_quantity;
    double weight;

public:
    physical_product(const string& t, const string& d, double p, const string& c,
                     int stock, double w)
        : Product(t, d, p, c), stock_quantity(stock), weight(w) {}

    bool reduce_stock(int qty) {
        if (qty <= 0) return false;
        if (stock_quantity >= qty) {
            stock_quantity -= qty;
            return true;
        }
        return false;
    }

    void increase_stock(int qty) {
        if (qty > 0) stock_quantity += qty;
    }

    void display(ostream& os) const override {
        os << "Physical Product [" << id << "]\n"
           << "Title: " << title << "\n"
           << "Description: " << description << "\n"
           << "Category: " << category << "\n"
           << "Price: $" << price << "\n"
           << "Price after discount: $" << price_after_discount() << "\n"
           << "Weight: " << weight << " kg\n"
           << "Stock: " << stock_quantity << "\n";
    }

    string get_type() const override {
        return "physical_product";
    }

    int get_stock_quantity() const { return stock_quantity; }
    double get_weight() const { return weight; }
};
