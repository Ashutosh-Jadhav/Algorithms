class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int end_time,ans = 0;
        sort(arr.begin(),arr.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto m : arr) {
            if (!pq.empty()) {
                end_time = pq.top();
                if (m[0] > end_time) pq.pop();
            }
            pq.push(m[1]);
            if (ans < pq.size()) ans = pq.size();
        }
        return ans;
    }
};
