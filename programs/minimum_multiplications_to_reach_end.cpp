// nice question

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) return 0;
        vector<int> v(100000,-1);
        queue<int> q;
        int u,v1,m=100000;
        q.push(start); v[start] = 0;
        while(!q.empty()) {
            u = q.front(); q.pop();
            for (int i = 0 ; i < arr.size() ; i++) {
                v1 = (u*arr[i]) % m;
                if (v1 == end) return v[u]+1;
                if (v[v1] == -1) {
                    v[v1] = v[u]+1; q.push(v1);
                }
            }
        }
        return -1;
    }
};
