#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Car {
    protected:
    string brand;
    string model;
    bool is_engine_on;
    int speed;

    public:
    Car(string b, string m) {
        this->brand = b;
        this->model = m;
        is_engine_on = false;
        speed = 0;
    }

    void StartEngine() {
        if (is_engine_on) cout << "Engine is already on." << endl;
        else cout << this->brand << " " << this->model << " : engine stated." << endl;
        this->is_engine_on = true;
    }

    void StopEngine() {
        if (!is_engine_on) return;
        this->is_engine_on = false;
        this->speed = 0;
        cout << "Engine Stopped" << endl;
    }

    void Accelerate() {
        if (!this->is_engine_on) return;
        this->speed += 20;
        cout << "Speed : " << this->speed << endl;
    }

    void Brake() {
        this->speed = max(0,this->speed - 20);
        cout << "Speed : " << this->speed << endl;
    }

    virtual ~Car() {}
};

class ManualCar : public Car {
    protected:
    int gear;

    public:
    ManualCar(string b, string m) : Car(b,m) {
        this->gear = 0;
    }

    void ChangeGear(int num) {
        this->gear = num;
        cout << "Gear : " << this->gear << endl;
    }
};

class ElectricCar: public Car {
    protected:
    int battery;

    public:
    ElectricCar(string m , string b) : Car(m,b) {
        this->battery = 100;
    }

    void ChargeBattery() {
        this->battery = 100;
        cout << "Battery : " << this->battery << endl;
    }
};

int main() {
    Car* manual = new ManualCar("Ford","Mustang");
    Car* electric = new ElectricCar("Tesela","S3");
    manual->StartEngine();
    manual->Accelerate();
    manual->Accelerate();
    manual->Brake();
    manual->StopEngine();

    cout << "---------------------------------------------" << endl;

    electric->StartEngine();
    electric->Accelerate();
    electric->Accelerate();
    electric->Brake();
    electric->StopEngine();

    delete manual;
    delete electric;
}