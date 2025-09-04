#include "product.h"

// ==================================== product =============================================================================================================================
long int Product::next_id = 206957;
double Product::global_discount = 0.0;
// ==================================== product =============================================================================================================================

// ==================================== Physical Product ====================================================================================================================

Physical_Product::Physical_Product(){}
Physical_Product::Physical_Product(string title,  string description, string category, double price, int stock, double weight)
    : Product(title, description, price, category), stock_quantity(stock), weight(weight) {}


bool Physical_Product::reduce_stock(int qty)
{
    if (qty <= 0) return false;

    if (stock_quantity >= qty)
    {
        stock_quantity -= qty;
        return true;
    }

    return false;
}
void Physical_Product::increase_stock(int qty)
{
    if (qty > 0) stock_quantity += qty;
}


void Physical_Product::display(ostream& os)
{
    os << "Product id [ " << get_id() << " ]\n"
       << "Title: " << get_title() << "\n"
       << "Description: " << get_description() << "\n"
       << "Category: " << get_category() << "\n"
       << "Price: " << get_price() << "$\n"
       << "Price after discount: " << price_after_discount() << "$\n"
       << "Weight: " << weight << " kg\n"
       << "Stock Quantity: " << stock_quantity << "\n\n";
}
string Physical_Product::get_type()
{
    return "Physical Product";
}
double Physical_Product::price_after_discount()
{
  return price - (price * global_discount/100.0);
}


int Physical_Product::get_quantity()   { return stock_quantity; }
double Physical_Product::get_weight()  { return weight; }


void Physical_Product::set_quantity(int qty)
{
    stock_quantity += qty;
}

istream& operator>>(istream& in, Physical_Product& p)
{
  cout << "\t\tPhysical Product\n";
  cout << "title & description & category & price & stock Quantity & weight\n";
    getline(in, p.title);
    getline(in, p.description);
    getline(in, p.category);

    in >> p.price >> p.stock_quantity >> p.weight;

    p.id = Product::next_id;
    Product::next_id++;
    in.ignore();
  return in;
}
ostream& operator<<(ostream& out, Physical_Product& p)
{
    p.display(out);
    return out;
}

// ==================================== Physical Product ====================================================================================================================

// ==================================== Digital Product ====================================================================================================================

Digital_Product::Digital_Product(){}
Digital_Product::Digital_Product(string title, string description, string category, string url, string format, double price, double size_mb)
    : Product(title, description, price, category), download_url(url), file_format(format), file_size_mb(size_mb) {}


void Digital_Product::display(ostream& os)
{
    os << "Product id [ " << get_id() << " ]\n"
       << "Title: " << get_title() << "\n"
       << "Description: " << get_description() << "\n"
       << "Category: " << get_category() << "\n"
       << "Price: " << get_price() << "$\n"
       << "Price after discount: " << price_after_discount() << "$\n"
       << "Download URL: " << download_url << "\n"
       << "File Format: " << file_format << "\n"
       << "File Size: " << file_size_mb << " MB\n\n";
}
string Digital_Product::get_type()
{
    return "Digital Product";
}
double Digital_Product::price_after_discount()
{
    return price - (price * global_discount/100.0);
}
int Digital_Product::get_quantity(){return 1e9;}


string Digital_Product::get_download_url()  { return download_url; }
string Digital_Product::get_file_format()  { return file_format; }
double Digital_Product::get_file_size_mb()  { return file_size_mb; }


istream& operator>>(istream& in, Digital_Product& p)
{
    cout << "\t\tDigital Product\n";
    cout << "title & description & category & url & format & price & size MB\n";
    getline(in, p.title);
    getline(in, p.description);
    getline(in, p.category);
    getline(in, p.download_url);
    getline(in, p.file_format);

    in >> p.price >> p.file_size_mb;

    p.id = Product::next_id;
    Product::next_id++;
    in.ignore();
    return in;
}
ostream& operator<<(ostream& out, Digital_Product& p)
{
    p.display(out);
    return out;
}

// ==================================== Digital Product ====================================================================================================================
