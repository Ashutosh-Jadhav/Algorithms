// User function Template for C++
class Solution {
  public:
  
    int find(int u, vector<int>& par) {
        if (par[u] != u) return par[u] = find(par[u],par);
        return u;
    }
    
    bool disjoint(int u, int v, vector<int>& par) {
        return find(u,par) != find(v,par);
    }
    
    void union_by_rank(int u , int v , vector<int>& r, vector<int>& par) {
        int uroot,vroot;
        uroot = find(u,par); vroot = find(v,par);
        if (uroot == vroot) return;
        if (r[uroot] > r[vroot]) {
            par[vroot] = uroot;
        }
        else if (r[vroot] > r[uroot]) {
            par[uroot] = vroot;
        }
        else {
            par[vroot] = uroot;
            r[uroot]++;
        }
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>r (V,0);
        vector<int>par(V,0);
        int u,v,w,ans=0;
        for (int i = 0 ; i < V ; i++) {
            par[i] = i ;
        }
        sort(edges.begin(),edges.end(),[](const vector<int>& a ,const vector<int>& b){return a[2] < b[2];});
        for (int i = 0 ; i < edges.size() ; i++) {
            u = edges[i][0]; v = edges[i][1]; w = edges[i][2];
            if (disjoint(u,v,par)) {
                union_by_rank(u,v,r,par);
                ans+=w;
            }
        }
        return ans;
    }
};