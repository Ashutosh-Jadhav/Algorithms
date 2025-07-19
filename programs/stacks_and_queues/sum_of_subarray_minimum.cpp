class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD = 1e9 + 7 ;
        long long n ,ans=0; n = arr.size();
        vector<int> n_s_r(n,n); vector<int> n_s_l(n,-1); stack<int> s;
        for (int i = 0 ; i < n ; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {n_s_r[s.top()] = i;s.pop();}
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0 ; i < n ; i++) {
            while(!s.empty() && arr[s.top()] > arr[n-i-1]) {n_s_l[s.top()] = n-i-1;s.pop();}
            s.push(n-i-1);
        }
        for (int i = 0 ; i < n ; i++) {
            ans = ans+ (i-n_s_l[i])%MOD*(n_s_r[i]-i)%MOD*arr[i]%MOD;
            ans = ans % MOD;
        }
        return ans;
    }
};