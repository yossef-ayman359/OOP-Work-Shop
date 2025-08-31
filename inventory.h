#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

template<typename T>
class Inventory {
private:
    std::vector<std::shared_ptr<T>> products;

public:
    // Add a product to inventory
    void add_product(std::shared_ptr<T> product) {
        if (product) {
            products.push_back(product);
        }
    }

    // Remove a product by ID
    bool remove_product(int id) {
        auto it = std::find_if(products.begin(), products.end(),
                              [id](const std::shared_ptr<T>& p) { return p->get_id() == id; });
        if (it != products.end()) {
            products.erase(it);
            return true;
        }
        return false;
    }

    // Find a product by ID
    std::shared_ptr<T> find_product(int id) const {
        auto it = std::find_if(products.begin(), products.end(),
                              [id](const std::shared_ptr<T>& p) { return p->get_id() == id; });
        return (it != products.end()) ? *it : nullptr;
    }

    // Find products by category
    std::vector<std::shared_ptr<T>> find_by_category(const std::string& category) const {
        std::vector<std::shared_ptr<T>> result;
        std::copy_if(products.begin(), products.end(), std::back_inserter(result),
                    [&category](const std::shared_ptr<T>& p) { 
                        return p->get_category() == category; 
                    });
        return result;
    }

    // Get all products
    const std::vector<std::shared_ptr<T>>& get_all_products() const {
        return products;
    }

    // Get total number of products
    size_t size() const {
        return products.size();
    }

    // Check if inventory is empty
    bool empty() const {
        return products.empty();
    }

    // Clear all products
    void clear() {
        products.clear();
    }

    // Display all products
    void display_all(std::ostream& os = std::cout) const {
        if (products.empty()) {
            os << "Inventory is empty.\n";
            return;
        }
        
        os << "=== INVENTORY (" << products.size() << " products) ===\n";
        for (const auto& product : products) {
            os << *product << "\n";
        }
        os << "========================\n";
    }

    // Calculate total value of inventory
    double get_total_value() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product->price_after_discount();
        }
        return total;
    }
};

#endif // INVENTORY_H
