#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string p = "geek";
    string t = "geeksforgeeks" ;
    int hash_val = 0, n = p.size(),hash_val_p=0 ;
    for (int i = 0 ; i < n ; i++) {
        hash_val_p += (int)p[i];
        hash_val_p %= 101;
    }
    for (int i = 0 ; i < t.size() ; i++) {
        hash_val += int(t[i]);
        // hash_val %= 101;
        if (i >= n) hash_val -= t[i-n];
        hash_val %= 101;
        if (i >= n-1 && hash_val == hash_val_p) {
            for (int k = 0 ; k < n ; k++) {
                if (p[k] != t[i-n+1+k]) break;
            }
            cout << "pattern found at : " << i-n+2 << endl;
        }
        cout << i << " : " <<  hash_val<<endl ;
    }
    cout << hash_val_p << endl;
    // char c = 99 ;
    // cout << c << endl;
    return 0;
}