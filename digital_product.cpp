#include "digital_product.h"
#include <iostream>

DigitalProduct::DigitalProduct(const std::string& t, const std::string& d, double p, const std::string& c,
                              const std::string& url, const std::string& format, double size_mb)
    : Product(t, d, p, c), download_url(url), file_format(format), file_size_mb(size_mb) {}

void DigitalProduct::display(std::ostream& os) const {
    os << "Digital Product [" << get_id() << "]\n"
       << "Title: " << get_title() << "\n"
       << "Description: " << get_description() << "\n"
       << "Category: " << get_category() << "\n"
       << "Price: $" << get_price() << "\n"
       << "Price after discount: $" << price_after_discount() << "\n"
       << "Download URL: " << download_url << "\n"
       << "File Format: " << file_format << "\n"
       << "File Size: " << file_size_mb << " MB\n";
}

std::string DigitalProduct::get_type() const {
    return "DigitalProduct";
}
