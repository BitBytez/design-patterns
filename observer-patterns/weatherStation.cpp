#include <bits/stdc++.h>
using namespace std;

// Observer interface
class IObserver {
public:
    virtual void update() = 0;
};

// Subject interface
class ISubject {
private:
    vector<IObserver*> observers; 
public: 
    void registerObserver(IObserver *ob){
        this->observers.push_back(ob);
        cout << "An Observer Registered" << endl;
    }
    void removeObserver(IObserver *r_ob){
        auto it = std::find(this->observers.begin(), this->observers.end(), r_ob);
        if (it != this->observers.end()) { 
            this->observers.erase(it); 
            cout << "An Observer Removed" << endl;
        }

    }
    void notifyObservers() {
        for(IObserver* ob : this->observers) {
            (*ob).update();
        }
    }
    virtual void getData() = 0;
};

// Concrete Classes
class CurrentConditions : public IObserver {
private:
    ISubject *subject;
public:
    CurrentConditions(ISubject *sub) {
        sub->registerObserver(this);
        this->subject = sub;
    }
    void update() {
        this->subject->getData();
        cout << "[Current Conditions] - Data Recieved" << endl;
    }
};

class ClimateConditions : public IObserver {
private:
    ISubject *subject;
public:
    ClimateConditions(ISubject *sub) {
        sub->registerObserver(this);
        this->subject = sub;
    }
    void update() {
        this->subject->getData();
        cout << "[Climate Conditions] - Data Recieved" << endl;
    }
};

class WeatherStation : public ISubject {
public:
    void getData() {
        // return whatever is required
        return;
    }
};

int main() {
    // Instantiate the Subject
    ISubject *ws = new WeatherStation();
    
    // Create observer by passing the subject to them 
    IObserver *clim = new ClimateConditions(ws);
    IObserver *curr = new CurrentConditions(ws);

    // notify all the observers
    ws->notifyObservers();

    // remove one observer
    ws->removeObserver(clim);

    // notify all the observers
    ws->notifyObservers();
}