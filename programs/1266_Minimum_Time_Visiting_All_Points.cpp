class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int max,tot,n; n = points.size(); tot = 0;
        for (int i = 0 ; i < n - 1 ;i++) {
            max = abs(points[i][0]-points[i+1][0]);
            if (abs(points[i][1]-points[i+1][1]) > max) max = abs(points[i][1]-points[i+1][1]);
            tot += max;
        }
        return tot;
    }
};