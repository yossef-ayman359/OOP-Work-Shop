#include "Payment.h"

void Credit_Card_Payment::User_info()
{
  cout << "\nEnter your name & phone number & address:\n";
  cin >> name >> phone_number >> address;
  cout << name << ", Your order will arrive within a maximum of 5 days.\n";
}

void Cash_On_Delivery::User_info()
{
     cout << "\nEnter your name & phone number & address:\n";
     cin >> name >> phone_number >> address;
     cout << name << ", Your order will arrive within a maximum of 5 days at the address : " << address << ".\n";
}

bool Credit_Card_Payment::process(double amount)
{
    Credit_Card_Payment::User_info();
    cout << "Processing credit card payment of: " << amount << endl;
    return true;
}

bool Cash_On_Delivery::process(double amount)
{
    Cash_On_Delivery::User_info();
    cout << "Cash on delivery: " << amount << endl;
    return true;
}