#ifndef PHYSICAL_PRODUCT_H
#define PHYSICAL_PRODUCT_H

#include "product.h"

class PhysicalProduct : public Product {
private:
    int stock_quantity;
    double weight;

public:
    PhysicalProduct(const std::string& t, const std::string& d, double p, const std::string& c,
                    int stock, double w);

    bool reduce_stock(int qty);
    void increase_stock(int qty);
    
    void display(std::ostream& os) const override;
    std::string get_type() const override;

    int get_stock_quantity() const { return stock_quantity; }
    double get_weight() const { return weight; }
};

#endif // PHYSICAL_PRODUCT_H
