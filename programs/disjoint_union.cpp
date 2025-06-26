// naive

/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if (par[x] == x) return x;
    else return find(par , par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int p_z ,p_x;
    p_x = find(par,x);
    p_z = find(par , z);
    par[p_x] = p_z;
    
}


//   union by size and rank

class DisjointSet {
    vector<int> parent;
    vector<int> s;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n,0);
        s.resize(n,1);
        for (int i = 0 ; i < n ; i++) {
            parent[i] = i ;
        }
    }

    int real_find(int i) {
        if (parent[i] != i) return parent[i] = real_find(parent[i]);
        return i;
    }

    bool find(int u, int v) {
        return real_find(u) == real_find(v);
    }

    void unionByRank(int u, int v) {
        int uroot,vroot;
        uroot = real_find(u);
        vroot = real_find(v);
        if (uroot == vroot) return;
        if (rank[uroot] > rank[vroot]) {
            parent[vroot] = uroot;
        }
        else if (rank[vroot] > rank[uroot]) {
            parent[uroot] = vroot;
        }
        else {
            parent[vroot] = uroot;
            rank[uroot]++;
        }
    }

    void unionBySize(int u, int v) {
       int uroot,vroot;
       uroot = real_find(u); vroot = real_find(v);
       if (uroot == vroot) return;
       if (s[uroot] > s[vroot]) {
            parent[vroot] = uroot;
            s[uroot] += s[vroot];
       }
       else {
            parent[uroot] = vroot;
            s[vroot] += s[uroot];
       }
    }
};

