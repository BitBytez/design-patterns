#include <string>
#include <iostream>
using namespace std;
// Interface OR Abstract Class

class IBeverage {
public:
    string description = "Unknown";
    virtual string getDescription(){
        return this->description;
    }
    virtual double cost() = 0;
};

class IDecorator : public IBeverage {
public:
    IBeverage *beverage;
};

class Espresso : public IBeverage {
public:
    Espresso() {
        this->description = "Espresso";
    }
    double cost() {
        return 2.0;
    }
};

class HouseBlend : public IBeverage {
public:    
    HouseBlend() {
        this->description = "HouseBlend";
    }
    double cost() {
        return 1.0;
    }
};

class Mocha : public IDecorator {
public:
    Mocha(IBeverage *bev) { 
        this->beverage = bev; 
    }
    
    string  getDescription() override {
        return this->beverage->getDescription() + ", Mocha";
    }

    double cost() {
        return this->beverage->cost() + 0.20;
    }
};


class Whip : public IDecorator {
public:
    Whip(IBeverage *bev) {
        this->beverage = bev; 
    }

    string getDescription() {
        return this->beverage->getDescription() + ", Whip";
    }

    double cost() {
        return this->beverage->cost() + 0.10;
    }
};

// Costs
/**
 * Espresso - 2.00
 * HouseBlend - 1.00
 * Mocha - 0.20
 * Whip - 0.10
**/


int main() {
    // This is our espresso Beverage
    IBeverage *esp = new Espresso(); // 2.0
    // Add Mocha to it
    esp = new Mocha(esp); // 2.0 + 0.20
    
    // Add Whip on it
    esp = new Whip(esp); // 2.0 + 0.20 + 0.10

    // Add MOcha again
    esp = new Mocha(esp); // 2.0 + 0.2 + 0.1 + 0.2

    // calculate the cost and the description
    cout << "[-] Cost : " << esp->cost() << endl; // 2.5
    cout << "[-] Desc : " << esp->getDescription() << endl;

    return 0;
}

