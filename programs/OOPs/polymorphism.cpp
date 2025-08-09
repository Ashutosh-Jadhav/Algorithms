#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ManualCar {
    protected:
    string brand;
    string model;
    int speed;
    bool is_engine_on;

    public:

    ManualCar(string b , string m) {
        this->brand = b;
        this->model = m;
        this->speed = 0;
        this->is_engine_on = false;
    }

    void StartEngine() {
        this->speed = 0;
        this->is_engine_on = true;
    }

    void StopEngine() {
        this->is_engine_on = false;
        this->speed = 0;
    }

    void Accelerate() {
        if (!is_engine_on) return;
        this->speed += 20;
        cout << "Speed : " << this->speed << endl;
    }

    void Accelerate(int num) {
        if (!is_engine_on) return;
        this->speed += num;
        cout << "Speed : " << this->speed << endl;
    }

    virtual ~ManualCar() {}
};

int main() {
    ManualCar * c = new ManualCar("Ford","Mustang");
    c->StartEngine();
    c->Accelerate();
    c->Accelerate(50);
    c->StopEngine();
    delete c;
}