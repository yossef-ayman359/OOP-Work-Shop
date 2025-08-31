#ifndef DIGITAL_PRODUCT_H
#define DIGITAL_PRODUCT_H

#include "product.h"

class DigitalProduct : public Product {
private:
    std::string download_url;
    std::string file_format;
    double file_size_mb;

public:
    DigitalProduct(const std::string& t, const std::string& d, double p, const std::string& c,
                   const std::string& url, const std::string& format, double size_mb);

    void display(std::ostream& os) const override;
    std::string get_type() const override;

    std::string get_download_url() const { return download_url; }
    std::string get_file_format() const { return file_format; }
    double get_file_size_mb() const { return file_size_mb; }
};

#endif // DIGITAL_PRODUCT_H
