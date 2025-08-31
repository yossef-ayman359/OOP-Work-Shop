cmake_minimum_required(VERSION 3.10)
project(OOP_Product_Management)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(product_management
    main.cpp
    product.cpp
    physical_product.cpp
    digital_product.cpp
)

# Include directories
target_include_directories(product_management PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Set compiler flags
if(MSVC)
    target_compile_options(product_management PRIVATE /W4)
else()
    target_compile_options(product_management PRIVATE -Wall -Wextra -Wpedantic)
endif()
