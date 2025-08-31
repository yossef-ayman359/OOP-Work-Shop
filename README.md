# OOP Product Management System

A comprehensive C++ Object-Oriented Programming project demonstrating inheritance, polymorphism, templates, and modern C++ features.

## Project Structure

```
/OOP-Work-Shop
│
├── product.h              # Abstract base class for all products
├── product.cpp            # Implementation of static members
├── physical_product.h     # Header for physical products
├── physical_product.cpp   # Implementation of physical products
├── digital_product.h      # Header for digital products
├── digital_product.cpp    # Implementation of digital products
├── inventory.h            # Template class for managing product collections
├── main.cpp              # Main program demonstrating all features
├── CMakeLists.txt        # CMake build configuration
└── README.md             # This file
```

## Features

### Core Classes

1. **Product** (Abstract Base Class)
   - Virtual destructor and pure virtual functions
   - Static global discount functionality
   - Unique ID generation
   - Operator overloading for comparison and output

2. **PhysicalProduct** (Derived Class)
   - Stock quantity management
   - Weight tracking
   - Stock reduction and increase methods

3. **DigitalProduct** (Derived Class)
   - Download URL management
   - File format and size tracking
   - Digital-specific display information

4. **Inventory** (Template Class)
   - Generic container for any product type
   - Add, remove, and find products
   - Category-based filtering
   - Total value calculation
   - Comprehensive display functionality

### OOP Concepts Demonstrated

- **Inheritance**: PhysicalProduct and DigitalProduct inherit from Product
- **Polymorphism**: Virtual functions for display and type identification
- **Encapsulation**: Private members with public interfaces
- **Templates**: Generic Inventory class
- **Smart Pointers**: Modern C++ memory management
- **Operator Overloading**: Custom output and comparison operators

## Building the Project

### Prerequisites
- CMake 3.10 or higher
- C++17 compatible compiler (GCC, Clang, or MSVC)

### Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
make

# Run the program
./product_management
```

## Program Output

The main program demonstrates:

1. **Product Creation**: Creating both physical and digital products
2. **Inventory Management**: Adding products to inventory
3. **Global Discounts**: Applying discounts to all products
4. **Stock Management**: Reducing and increasing physical product stock
5. **Category Filtering**: Finding products by category
6. **Polymorphism**: Displaying different product types
7. **Inventory Operations**: Calculating total value and removing products

## Key Features

- **Type Safety**: Strong typing with C++17 features
- **Memory Safety**: Smart pointers prevent memory leaks
- **Extensibility**: Easy to add new product types
- **Template Flexibility**: Inventory works with any Product-derived class
- **Modern C++**: Uses contemporary C++ idioms and best practices

## Learning Objectives

This project serves as an excellent learning tool for:

- Understanding inheritance hierarchies
- Implementing virtual functions and polymorphism
- Working with templates and generic programming
- Using smart pointers for memory management
- Applying modern C++ features and idioms
- Building maintainable and extensible code

## Future Enhancements

Potential improvements could include:

- Database integration for persistent storage
- GUI interface using Qt or similar framework
- Network functionality for remote inventory management
- Advanced search and filtering capabilities
- Order processing and customer management
- Reporting and analytics features
