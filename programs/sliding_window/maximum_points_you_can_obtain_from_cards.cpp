class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum,n,m,l,curr_sum; sum = 0 ; n = cardPoints.size(); m = 0; l = 0; curr_sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += cardPoints[i];
            if (i == n-k-1) curr_sum = sum;
        }
        m = curr_sum;
        for (int i = n-k ; i < n ; i++) {
            curr_sum -= cardPoints[l];
            l++;
            curr_sum += cardPoints[i];
            m = min(m,curr_sum);
        }
        return sum - m;
    }
};