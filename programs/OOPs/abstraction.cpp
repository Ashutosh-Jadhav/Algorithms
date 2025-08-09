#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Car {
    public :
    string brand;
    string model;
    int speed;
    bool is_engine_on;

    virtual void StartCar() = 0;
    virtual void Accelerate() = 0;
    virtual void Brake() = 0;
    virtual void StopEngine() = 0;
    virtual ~Car() {}
};

class SportsCar:public Car {
    public:
    string brand;
    string model;
    int speed;
    bool is_engine_on;

    SportsCar(string brand, string model) {
        this->brand = brand;
        this->model = model;
        speed = 0;
        is_engine_on = false;
    }

    void StartCar() {
        this->is_engine_on = true;
        cout << this->brand << " " << this->model << " :  Engine stated. " <<endl;
    }

    void Accelerate() {
        if (!this->is_engine_on) cout << "engine is off" << endl;
        else this->speed += 20;
        cout << "Speed : " << this->speed << endl; 
    }

    void Brake() {
        if (this->speed == 0) cout << "car is not moving" << endl;
        else this->speed = max(0,this->speed-20);
        cout << "Speed : " << this->speed << endl;
    }

    void StopEngine() {
        this->speed = 0;
        this->is_engine_on = false;
    }
};

int main() {
    Car* c = new SportsCar("Ford","Mustang");
    c->StartCar();
    c->Accelerate();
    c->Accelerate();
    c->Brake();
    c->StopEngine();
    cout <<"Speed : " << c->speed << endl;
    cout << "Status of Car : " << c->is_engine_on << endl;
}