#include <bits/stdc++.h>
using namespace std;

class my_class {
    public:
        int my_int;
        string my_string;
    public:
        my_class() {
            my_int = 2;
            my_string = "Hello There";
        }
        my_class(int i, string s) {
            my_int = i;
            my_string = s;
        }
        void get_string() {
            cout << my_string << endl; 
        }
        void get_string(string s) {
            cout << s<< endl;
        }
        virtual void get_decimal(){};
        // virtual void get_decimal() = 0;
        virtual void get_bool(){};
        ~my_class() {cout << "destructor1" << endl;}
};

class my_class2:public my_class {
    public:
        float my_decimal;
    public:
        my_class2(){
            my_decimal = 3.2;
        }
        void get_string(string s) {
            cout << "string is " << s << endl;
        }
        void get_decimal(){
            cout << my_decimal << endl;
        }
        virtual void get_bool(){};
        ~my_class2(){cout << "destructor2" << endl;}
};

class my_class3:public my_class2{
    public:
        float my_bool;
    public:
        my_class3() {
            my_bool = true;
        }
        void get_bool() {
            cout << this->my_bool << endl;
        }
        ~my_class3(){cout << "destructor3" << endl;}
};

int main() {
    my_class c1(10,"hi");
    my_class2 c2 ;
    // c1.get_string();
    // c2.get_string();
    // c1.get_string("passed_input");
    c2.get_string("input2");
    my_class2 *p = new my_class2();
    p->get_string("input3");
    p->get_decimal();
    p->get_bool();
    delete p;
    
    return 0;
}