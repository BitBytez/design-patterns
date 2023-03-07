#include <iostream>
using namespace std;

class IFlyBehaviour {
    public:
    virtual void fly() = 0;
};

class FlyWithWingsBehaviour : public IFlyBehaviour {
    void fly() {
        cout << "Flying with Wings" << endl;
    }
};

class NoFlyBehaviour :public IFlyBehaviour {
    void fly() {
        cout << "Cannot Fly" << endl;
    }
};

class Duck {

protected:
    IFlyBehaviour *flyBehaviour;
public:
    void swim() {
        cout << "Swimming" << endl;
    }
    void fly() {
        this->flyBehaviour->fly();
    }
    void setFlyBehaviour(IFlyBehaviour *fb) {
        this->flyBehaviour = fb;
    }
};

class RubberDuck : public Duck{
public:
    RubberDuck() {
        this->flyBehaviour = new NoFlyBehaviour();
    }
};


int main() {
    IFlyBehaviour *flyBeh = new FlyWithWingsBehaviour();
    Duck *rd = new RubberDuck();
    rd->fly(); // By Default Rubber Duck has NoFlyBehaviour => Cannot Fly
    // Give super Powers to Rubber Duck
    rd->setFlyBehaviour(flyBeh);
    rd->fly();
    return 0;
}