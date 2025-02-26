#include <bits/stdc++.h>
using namespace std;
int main(){
    float t,n,k,p ;
    cin >> t ;
    while(t--){
        cin >> n >> k >> p;
        if (k < 0) k = -1 * k;
        if (ceil(k/p) > n) cout << -1 << endl;
        else cout << ceil(k/p) << endl; 
    }
}