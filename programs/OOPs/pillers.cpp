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

    virtual void Accelerate() = 0;

    virtual void Accelerate(int num) = 0;

    virtual void Brake()  = 0;

    virtual ~Car() {}
};

class ManualCar : public Car {
    protected:
    int gear;

    public:
    ManualCar(string b, string m) : Car(b,m) {
        this->gear = 0;
    }

    void Accelerate() {
        this->speed += 20;
        if (this->speed > 10) this->gear = 2;
        cout << "Gear : " << this->gear << endl;
        cout << "Speed : " << this->speed << endl;

    }

    void Accelerate(int num) {
        this->speed += num;
        cout << "Speed : " << this->speed << endl;
    }

    void Brake() {
        this->speed = max(0,this->speed-15);
        cout << "Speed : " << this->speed << endl;
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

    void Accelerate() {
        this->speed += 15;
        cout << "Speed : " << this->speed << endl;
    }

    void Accelerate(int num) {
        this->speed += num;
        cout << "Speed : " << this->speed << endl;
    }

    void Brake() {
        this->speed = max(0,this->speed-15);
        cout << "Speed : " << this->speed << endl;
    }

    ElectricCar(string b , string m) : Car(b,m) {
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
    // manual->ChangeGear(2);
    manual->Accelerate(30);
    // manual->ChangeGear(3);
    manual->Brake();
    manual->Brake();
    manual->Brake();
    manual->Brake();
    manual->Brake();
    manual->StopEngine();

    cout << "---------------------------------------------" << endl;

    electric->StartEngine();
    electric->Accelerate();
    electric->Accelerate();
    electric->Brake();
    electric->Brake();
    electric->StopEngine();
    // electric->ChargeBattery();

    delete manual;
    delete electric;
}