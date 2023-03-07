#include <string>
#include <iostream>
using namespace std;


class IPaymentStrategy {
public:
    virtual void pay() = 0;
};

class PayPalStrategy : public IPaymentStrategy {
private:
    string name, email;
public: 
    PayPalStrategy(string name,string email) {
        this->name = name;
        this->email = email;
    }
    void pay() {
        cout << "PayPal Payment Successful" << endl;
    }
};

class CreditCardStrategy : public IPaymentStrategy {
private:
    string creditCardNumber, expiryDate, creditCardHolderName;
public: 
    CreditCardStrategy(string ccn, string exp, string cchn) {
        this->creditCardNumber = ccn;
        this->expiryDate = exp;
        this->creditCardHolderName = cchn;
    }
    void pay() {
        cout << "CreditCard Payment Successful" << endl;
    }
};

class Item {
protected:
    int price;
    IPaymentStrategy *pymnt;
public:
    Item(IPaymentStrategy *p) {
        this->pymnt = p;
    }
    void doPayment() {
        this->pymnt->pay();
    }
    void setPayment(IPaymentStrategy *pp) {
        this->pymnt = pp;
    }
};

int main() {
    IPaymentStrategy *paypal = new PayPalStrategy("name","email");
    IPaymentStrategy *cc = new CreditCardStrategy("account-number", "exp-date", "cc-holder-number");

    Item *I1 = new Item(paypal);
    I1->doPayment();

    // Change the Payment Method / Strategy
    I1->setPayment(cc);
    
    
    I1->doPayment();
    return 0;
}