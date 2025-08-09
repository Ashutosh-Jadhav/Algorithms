#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SportsCar{
    private:
    string brand;
    string model;
    int speed;
    bool is_engine_on;
    string tyre;

    public:

    // getters and setters

    int getSpeed() {
        return this->speed;
    }

    int getEngineStatus() {
        return this->is_engine_on;
    }

    void setTyre(string t) {
        // can put validate conditions or anything else before setting the value
        this->tyre = t;
    }

    string getTyre() {
        return this->tyre;
    }

    SportsCar(string brand, string model) {
        this -> brand = brand;
        this->model = model;
        speed = 0;
        is_engine_on = false;
        tyre = "MRF";
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
    SportsCar* c = new SportsCar("Ford","Mustang");
    c->StartCar();
    c->Accelerate();
    cout <<"Speed : " << c->getSpeed() << endl;
    c->Accelerate();
    c->Brake();
    c->StopEngine();
    // c->speed = 100;
    cout << "Tyre : " << c->getTyre() << endl;
    c->setTyre("CEAT");
    cout << "Tyre : " << c->getTyre() << endl;
    cout <<"Speed : " << c->getSpeed() << endl;
    cout << "Status of Car : " << c->getEngineStatus() << endl;
}