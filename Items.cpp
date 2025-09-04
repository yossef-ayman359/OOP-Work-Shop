#include "Items.h"

// ====================================== Cart ================================

Cart_Item::Cart_Item(Product* p, int quantity) : p(p), quantity(quantity)
{
  if (quantity > p->get_quantity() && p->get_quantity() != -(1e9))
  {
      int q;
      cout << "The available quantity = " << p->get_quantity() << "\n\tEnter correct quantity.\n";
      while (cin>>q)
      {
          if (q <= p->get_quantity())
          {
              this->quantity = q;
              break;
          }
          cout << "\tPlease, Enter number from 1 to " << p->get_quantity() << endl;
      }
  }
}

double Cart_Item::subtotal() const
{
  return p->price_after_discount() * (double) quantity;
}

ostream& operator>>(ostream& out, Product* &p)
{
  p->display(out);
  return out;
}

// ====================================== Shopping ================================

void apply_Discount(Shopping_Cart cart, double discount)
{
    cout << "Total price after discount = " << cart.calculateTotal() - (cart.calculateTotal() * (discount + cart.items[0].p->get_global_discount()) / 100.0) << endl;
}


void Shopping_Cart::addItem(Product* p, int quantity)
{
    items.push_back({p, quantity});
}
void Shopping_Cart::addItem(Cart_Item temp)
{
    items.push_back(temp);
}
void Shopping_Cart::removeItem(int id)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->p->get_id() == id)
        {
            items.erase(it);
        }
    }
}
void Shopping_Cart::update_Quantity(int id, int qty)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->p->get_id() == id)
        {
            it->quantity = qty;
        }
    }
}
void Shopping_Cart::sort_by_Price()
{
    sort(items.begin(), items.end(), [] (Cart_Item x, Cart_Item y) {return x.p->get_price() < y.p->get_price() ;} );
}
double Shopping_Cart::calculateTotal()
{
    return accumulate(items.begin(), items.end(), 0.0, [] (double total, Cart_Item x) {return total + x.subtotal(); } );

}


ostream& operator<<(ostream& out, Shopping_Cart& cart)
{
    for (auto it : cart.items)
    {
        it.p->display(out);
        out << "Quantity you need: " << it.quantity << endl;
        out << "===============================\n";
    }
    return out;
}

Shopping_Cart Shopping_Cart::operator+(Shopping_Cart cart)
{
    for_each(cart.items.begin(), cart.items.end(), [this] (Cart_Item x) {this->items.push_back(x);});
    return *this;
}

// ====================================== inventory ================================

template<class T>

void inventory<T>::add_item(T& product)
{
    products.push_back(product);
}
template<class T>

void inventory<T>::remove_item(int id)
{
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if (it->get_id() == id)
        {
            products.erase(it);
            --it;
        }
    }
}
template<class T>

void inventory<T>::sort_by_price(bool asc /* = true */)
{
    sort(products.begin(), products.end(),
         [asc](T& a, T& b) {
             return asc ? (a.get_price() < b.get_price())
                        : (a.get_price() > b.get_price());
         });
}


template<class T>

T* inventory<T>::find_by_id(int id)
{
    for (auto& product : products)
    {
        if (product.get_id() == id)
            return &product;
    }
    return nullptr;
}


template<class T>

vector<T> inventory<T>::search_by_title(string title)
{
    vector<T> result;
    for (auto& product : products)
    {
        if (product.get_title() == title)
        {
            result.push_back(product);
        }
    }
    return result;
}

template<class T>
vector<T>& inventory<T>::get_products()
{
    return products;
}