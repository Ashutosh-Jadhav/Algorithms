class Solution {
public:
    int find(int u , vector<int>& par) {
        if (par[u] != u) return par[u] = find(par[u],par);
        return u;
    }
    bool disjoint(int u , int v , vector<int>& par){
        return find(u,par) != find(v,par);
    }
    void union_by_rank(int u, int v , vector<int>& par,vector<int>& rank) {
        int vroot, uroot;
        vroot = find(v,par); uroot = find(u,par);
        if (vroot == uroot) return;
        if (rank[vroot]> rank[uroot]) {
            par[uroot] = vroot;
        }
        else if (rank[uroot] > rank[vroot]) par[vroot] = uroot;
        else {
            par[vroot] = uroot;
            rank[uroot]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n,ans; n = stones.size(); ans = n;
        pair<int,int> u,v;
        vector<int> par(n);
        vector<int> rank(n,0);
        for (int i = 0 ; i < n ; i++) {
            par[i] = i ;
        }
        for (int i =0 ; i < n ; i++) {
            u = make_pair(stones[i][0],stones[i][1]);
            for (int j = i+1 ; j < n ; j++) {
                v = make_pair(stones[j][0],stones[j][1]);
                if (v.first == u.first || u.second == v.second) {
                    if (disjoint(i,j,par)) {
                        ans--;
                        union_by_rank(i,j,par,rank);
                    }
                }
            }
        }
        cout << ans << endl;
        return n-ans;
    }
};