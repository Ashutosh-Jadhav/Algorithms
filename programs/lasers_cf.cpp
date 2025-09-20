#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int t,n,m,ans=0;
    long long x,y;
    // vector<int> as;
    // vector<int> bs;
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        ans = 0;
        vector<int> as(n,0);
        vector<int> bs(m,0);
        for (int i = 0 ; i < n ; i++) {
            cin >> as[i];
            if (as[i] <= y && as[i] >= 0) ans++;
        }
        for (int i = 0 ; i < m ; i++) {
            cin >> bs[i];
            if (bs[i] <= x && bs[i] >= 0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}