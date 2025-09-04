#ifndef PAYMENT_H
#define PAYMENT_H

#include "Items.cpp"

class Payment
{
protected:
    string name, phone_number, address;

public:
    virtual bool process(double amount) = 0;
};

// ===================================================

class Credit_Card_Payment : public Payment
{
public:
    void User_info();

    bool process(double amount) override;
};

// ============================================================

class Cash_On_Delivery : public Payment
{
public:
    void User_info();

    bool process(double amount) override;
};



#endif //PAYMENT_H
