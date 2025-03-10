#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class base{
    public:
        int num1,num2;
    protected:
        void init(int a,int b){
            num1 = a;
            num2 = b;
        }
    };

class Area: protected base {
        protected :

            int area(){
                return num1*num2;
            }
        };

class Perimeter: protected base {
            protected :

                int peri(){
                    return 2*(num1+num2);
                }
            };

int main(){
    int a , b ;
    cin >> a >> b ;
    Area a1 ;
    Perimeter p1 ;
    a1.init(a,b);
    p1.init(a,b);
    cout << a1.area() << endl;
    cout << p1.peri() << endl;
}