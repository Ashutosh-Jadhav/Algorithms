// User function Template for C++

class Solution {
  public:
    long long countKdivPairs(int A[], int n, int K) {
        // code here
        long long c,r,t; c = 0;
        vector<int> rem(K,0);
        for (int i = 0 ; i < n ; i++) {
            r = A[i] %K;
            rem[r]++;
        }
        // for (auto m : rem) cout << m << " ";
        for (int i = 0 ; i < K/2 + 1 ; i++) {
            if (i == 0) c += rem[i]*(max(rem[i]-1,0))/2;
            else {
                if (i == K-i) {
                    c += rem[i]*max(rem[K-i]-1,0)/2;
                }
                else c += rem[i]*rem[K-i];
            }
            
            // cout << c << endl;
        }
        return c;
    }
};