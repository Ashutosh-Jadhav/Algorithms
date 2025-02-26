#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t ,n, c1=0 , c2 = 0;
    string s ;
    cin >> t ;
    while(t--){
        c1 = 0 ; c2 = 0 ;
        cin >> n ;
        cin >> s ;
        for (int i = 0 ; i < n ; i++){
            if (s[i] == '-') c1++;
            else c2++ ;
        }
        if (c1 < 2 || c2 < 1) cout << 0 << endl;
        else {
            if (c1%2 == 0) cout << (c1/2)*(c1/2)*c2 << endl;
            else cout << (c1/2)*(c1/2+1)*c2 << endl;
        }
    }
}