#include <iostream>
#include <memory>
#include "product.h"
#include "physical_product.h"
#include "digital_product.h"
#include "inventory.h"

int main() {
    std::cout << "=== OOP Product Management System ===\n\n";

    // Create an inventory to store all products
    Inventory<Product> inventory;

    // Create some physical products
    auto laptop = std::make_shared<PhysicalProduct>(
        "Gaming Laptop", 
        "High-performance gaming laptop with RTX 4080", 
        1999.99, 
        "Electronics", 
        10, 
        2.5
    );

    auto book = std::make_shared<PhysicalProduct>(
        "C++ Programming Guide", 
        "Comprehensive guide to modern C++ programming", 
        49.99, 
        "Books", 
        25, 
        0.8
    );

    // Create some digital products
    auto software = std::make_shared<DigitalProduct>(
        "Photo Editor Pro", 
        "Professional photo editing software", 
        89.99, 
        "Software", 
        "https://download.example.com/photo-editor", 
        "exe", 
        150.5
    );

    auto ebook = std::make_shared<DigitalProduct>(
        "Data Structures & Algorithms", 
        "Complete guide to DSA with examples", 
        29.99, 
        "E-Books", 
        "https://download.example.com/dsa-ebook", 
        "pdf", 
        8.2
    );

    // Add products to inventory
    inventory.add_product(laptop);
    inventory.add_product(book);
    inventory.add_product(software);
    inventory.add_product(ebook);

    // Display all products
    std::cout << "Initial Inventory:\n";
    inventory.display_all();

    // Set a global discount
    Product::set_global_discount(0.15); // 15% discount
    std::cout << "\nAfter applying 15% global discount:\n";
    inventory.display_all();

    // Demonstrate stock management for physical products
    std::cout << "\n=== Stock Management Demo ===\n";
    if (auto found_laptop = std::dynamic_pointer_cast<PhysicalProduct>(inventory.find_product(laptop->get_id()))) {
        std::cout << "Laptop stock before: " << found_laptop->get_stock_quantity() << "\n";
        found_laptop->reduce_stock(3);
        std::cout << "Laptop stock after selling 3: " << found_laptop->get_stock_quantity() << "\n";
        found_laptop->increase_stock(5);
        std::cout << "Laptop stock after restocking 5: " << found_laptop->get_stock_quantity() << "\n";
    }

    // Find products by category
    std::cout << "\n=== Products by Category ===\n";
    auto electronics = inventory.find_by_category("Electronics");
    std::cout << "Electronics products (" << electronics.size() << "):\n";
    for (const auto& product : electronics) {
        std::cout << "- " << product->get_title() << " ($" << product->price_after_discount() << ")\n";
    }

    // Demonstrate polymorphism
    std::cout << "\n=== Polymorphism Demo ===\n";
    std::cout << "Product types in inventory:\n";
    for (const auto& product : inventory.get_all_products()) {
        std::cout << "- " << product->get_title() << " (" << product->get_type() << ")\n";
    }

    // Calculate total inventory value
    std::cout << "\n=== Inventory Summary ===\n";
    std::cout << "Total products: " << inventory.size() << "\n";
    std::cout << "Total inventory value: $" << inventory.get_total_value() << "\n";

    // Remove a product
    std::cout << "\n=== Removing Product ===\n";
    if (inventory.remove_product(book->get_id())) {
        std::cout << "Book removed successfully!\n";
        std::cout << "Remaining products: " << inventory.size() << "\n";
    }

    // Final inventory display
    std::cout << "\nFinal Inventory:\n";
    inventory.display_all();

    return 0;
}
