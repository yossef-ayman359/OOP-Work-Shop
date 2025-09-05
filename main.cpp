// #include "Users.cpp"
#include "Shop.cpp"

#define pp Physical_Product
#define dp Digital_Product

int main()
{
    // p1 id = 206957, p2 id = 206958

    Physical_Product p1("phone", "oppo reno 12x", "smart phone", 12500, 15, 1),
    p2 ("lab", "iphone X", "smart phone", 20000, 90, .5);
    Digital_Product px("ebook", "fantasy book", "book", "ncdn", "pdf" ,30, 150);

    // inventory<dp> inv;
    // Credit_Card_Payment ccp;
    // ccp.process(1500);
    // Cart_Item crt(&px, 50);
    // Shopping_Cart scrt;

    // Admin ad;
    // ad.add_Product(&p1);
    // ad.add_Product(&p2);
    // ad.add_Product(&px);
    Customer c1, c2;
    c1.add_to_cart(&p1, 2);
    c2.add_to_cart(&p2, 2);
    Shop sh;
    sh.register_customer(&c1);
    sh.register_customer(&c2);

    sh.add_item(&p1);
    sh.add_item(&p2);

    //
    // // cout << ad;
    // cout << "========================================================\n";
    //
    // ad.edit_Product(206957, 0, -11);
    // ad.edit_Product(206958, 20, -85);
    // ad.edit_Product(206959, 200, 20);
    //
    // // cout << ad;
    //
    // cout << ad.view_Reports();
    //
    // Credit_Card_Payment ccp;
    // ccp.process(1500);
    //
    // Cash_On_Delivery cod;
    // cod.process(2500);


    return 0;
}
