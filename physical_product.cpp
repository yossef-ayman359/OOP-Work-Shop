#include "physical_product.h"
#include <iostream>

PhysicalProduct::PhysicalProduct(const std::string& t, const std::string& d, double p, const std::string& c,
                                int stock, double w)
    : Product(t, d, p, c), stock_quantity(stock), weight(w) {}

bool PhysicalProduct::reduce_stock(int qty) {
    if (qty <= 0) return false;
    if (stock_quantity >= qty) {
        stock_quantity -= qty;
        return true;
    }
    return false;
}

void PhysicalProduct::increase_stock(int qty) {
    if (qty > 0) stock_quantity += qty;
}

void PhysicalProduct::display(std::ostream& os) const {
    os << "Physical Product [" << get_id() << "]\n"
       << "Title: " << get_title() << "\n"
       << "Description: " << get_description() << "\n"
       << "Category: " << get_category() << "\n"
       << "Price: $" << get_price() << "\n"
       << "Price after discount: $" << price_after_discount() << "\n"
       << "Weight: " << weight << " kg\n"
       << "Stock: " << stock_quantity << "\n";
}

std::string PhysicalProduct::get_type() const {
    return "PhysicalProduct";
}
