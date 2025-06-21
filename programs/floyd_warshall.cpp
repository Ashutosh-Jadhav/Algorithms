class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        const int INF = 100000000;
        int n,u,v,w; n = dist.size();
        vector<vector<vector<int>>> ans(n+1,vector<vector<int>> (n,vector<int> (n,0)));
        ans[0] = dist;
        for (int k = 1 ; k <= n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j =0 ; j < n ; j++) {
                    if (ans[k-1][k-1][j] == INF || ans[k-1][i][k-1] == INF) {ans[k][i][j] = ans[k-1][i][j]; continue;}
                    if (ans[k-1][i][j] < ans[k-1][i][k-1] + ans[k-1][k-1][j]) ans[k][i][j] = ans[k-1][i][j];
                    else ans[k][i][j] = ans[k-1][i][k-1] + ans[k-1][k-1][j];
                }
            }
        }
        dist = ans[n];
    }
};

// space optimized

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        const int INF = 100000000;
        int n,u,v,w; n = dist.size();
        vector<vector<vector<int>>> ans(2,vector<vector<int>> (n,vector<int> (n,0)));
        ans[0] = dist;
        for (int k = 1 ; k <= n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j =0 ; j < n ; j++) {
                    if (ans[(k-1)%2][k-1][j] == INF || ans[(k-1)%2][i][k-1] == INF) {ans[k%2][i][j] = ans[(k-1)%2][i][j]; continue;}
                    if (ans[(k-1)%2][i][j] < ans[(k-1)%2][i][k-1] + ans[(k-1)%2][k-1][j]) ans[k%2][i][j] = ans[(k-1)%2][i][j];
                    else ans[k%2][i][j] = ans[(k-1)%2][i][k-1] + ans[(k-1)%2][k-1][j];
                }
            }
        }
        dist = ans[n%2];
    }
};

// in-place 

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        for (int k = 0 ; k < n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    if (dist[i][k] + dist[k][j] > 100000) continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
};