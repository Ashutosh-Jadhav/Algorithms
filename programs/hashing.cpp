#include <bits/stdc++.h>
using namespace std ;

int h(int x,int n) {
    return (x % 107) % (n) ;
}

void Add(vector<int>& t , int x){
    int i = h(x,t.size());
    while(t[i] && t[i]!=x) {i++;}
    t[i] = x ;
}

void del(vector<int>& t , int x){
    int i = h(x,t.size());
    while(t[i] != x && t[i]) {i++;}
    if (!t[i]) cout << "value not present" << endl;
    else t[i] = 0 ;
}

int ser(vector<int>& t , int x){
    int i = h(x,t.size());
    while(t[i] != x && t[i]) {i++;}
    if (t[i]) return i;
    else return -1;
}

int main()
{
    int n,c,x,i=0 ;
    cout << "Enter the size of the array" << endl;
    cin >> n ;
    vector<int> t(2*n,0);
    while(1){
        cout << "1. Add to Array\n2. delete from array\n3. Search in array\n4. display\n5. Exit\nEnter choice : " ;
        cin >> c ;
        while (c > 5 || c < 1) {cout << "Enter between 1 to 3 : "; cin >> c;}
        if (c == 1){
            cout << "Enter value : ";
            cin >> x ;
            Add(t,x) ;
        }
        else if (c == 2){
            cout << "Enter value to delete : ";
            cin >> x ;
            del(t,x);
        }
        else if (c == 3) {
            cout << "Enter value to search : ";
            cin >> x ;
            i = ser(t,x);
            cout << i << endl;
        }
        else if (c == 4) {
            for (int m : t){
                cout << m << " ";
            }
            cout << endl ;
        }
        else break;
    }
}