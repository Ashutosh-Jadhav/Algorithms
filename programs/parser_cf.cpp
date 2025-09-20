#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t,n,m,a,b,ans,diff;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        ans =0;
        vector<vector<long long>> nums;
        nums.push_back({0,0});
        for (int i = 1 ; i < n+1 ; i++) {
            cin >> a >> b ;
            nums.push_back({a,b});
            diff = nums[i][0] - nums[i-1][0]; 
            if (diff %2 == 0) {
                if (nums[i][1] == nums[i-1][1]) ans+=diff;
                else ans += diff -1;
            }
            else {
                if (nums[i][1] == nums[i-1][1]) ans += diff -1 ;
                else ans += diff;
            }
        }
        cout << ans << endl;
    }
    return 0;
}