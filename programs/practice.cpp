#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<int>& nums, int k) {
    int curr,ans=0;
    priority_queue<int> pq;
    for (int i = 0 ; i <  nums.size() ; i++) {
        if (nums[i] > 0) pq.push(nums[i]);
    }
    for (int i = 0 ; i < k ; i++) {
        if (pq.empty()) break;
        curr = pq.top(); pq.pop();
        ans += curr;
        curr--;
        if (curr > 0) pq.push(curr);
    }
    return ans;
}

int main() {
    // priority_queue<int,vector<int>,greater<int>> pq;
    int k,n,ans;
    cin >> n >> k; 
    vector<int> nums(n,0);
    for (int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }
    ans = func(nums,k);
    cout << ans << endl;
    return 0;
}