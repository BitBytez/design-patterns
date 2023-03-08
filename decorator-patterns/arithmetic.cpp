#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

/**
 * Not a Good Usecase for the Decorator Pattern
 * But, good to understand and implement this.
*/


class Number {
public:
    float integer;
    virtual float Operation() = 0;
    virtual string Description() = 0;
};

string float_to_str(float f){
    stringstream stream;
    stream << fixed << setprecision(2) << f;
    return stream.str();

}

class Decorator : public Number {
public:
    Number *number;
};

class ConcreteNumber :public Number {
    public:
    ConcreteNumber(float integer) {
        this->integer = integer;
    }
    float Operation() override {
        return this->integer;
    }

    string Description() override  {
        return "(" + float_to_str(this->integer) +")";
    }

};

class Multiply : public Decorator {
private:
    float value = 1;
public:
    Multiply(Number *num,float value) {
        this->number = num;
        this->value = value;
    }
    float Operation() {
        return this->number->Operation() * this->value;
    }
    string Description() override  {
        return "(" + this->number->Description() + " * " + float_to_str(this->value) +")";
    }
};

class Divide : public Decorator {
private:
    float value;
public:
    Divide(Number *num,float value) {
        this->number = num;
        this->value = value;
    }
    float Operation() {
        return this->number->Operation() / this->value;
    }
    string Description() override  {
        return "(" + this->number->Description() + " / " + float_to_str(this->value) +")";
    }
};

class Add : public Decorator {
private:
    float value;
public:
    Add(Number *num,float value) {
        this->number = num;
        this->value = value;
    }
    float Operation() {
        return this->number->Operation() + this->value;
    }
    string Description() override  {
        return "(" + this->number->Description() + " + " + float_to_str(this->value) +")";
    }
};

class Subtract : public Decorator {
private:
    float value;
public:
    Subtract(Number *num,float value) {
        this->number = num;
        this->value = value;
    }
    float Operation() {
        return this->number->Operation() - this->value;
    }
    string Description() override  {
        return "(" + this->number->Description() + " - " + float_to_str(this->value) +")";
    }
};


int main() {
    Number *num = new ConcreteNumber(5);
    cout << num->Description() << " = " << num->Operation()<< endl;
    
    num = new Multiply(num, 5);
    cout << num->Description() << " = " << num->Operation()<< endl;
    
    num = new Divide(num, 3);
    cout << num->Description() << " = " << num->Operation()<< endl;
 
    num = new Add(num, 5);
    cout << num->Description() << " = " << num->Operation()<< endl;
 
    num = new Subtract(num, 10);
    cout << num->Description() << " = " << num->Operation() << endl;
    
    return 0;
}