#include <bits/stdc++.h>
using namespace std;

const int MAXV = 450;   // enough for n1 + n2 + 4
const int INF  = (int)1e9;

struct Edge {
    int to, cap, flow, cost;
    Edge() {}
    Edge(int _to, int _cap, int _flow, int _cost)
        : to(_to), cap(_cap), flow(_flow), cost(_cost) {}
};

int n1, n2, m, rCost, bCost;
string sL, sR;
int U[205], Vv[205];

vector<Edge> edges;
vector<int> adj[MAXV];

int S, T;          // artificial source/sink for lower-bound model
int oldS, oldT;    // original "super" nodes
int numV;          // total number of vertices

int bal[205][205]; // net flow per (left,right) pair

// add directed edge u -> v with capacity cap and cost cost
void addEdge(int u, int v, int cap, int cost) {
    adj[u].push_back((int)edges.size());
    edges.emplace_back(v, cap, 0, cost);
    adj[v].push_back((int)edges.size());
    edges.emplace_back(u, 0, 0, -cost);
}

inline int residual(int id) {
    return edges[id].cap - edges[id].flow;
}

// add edge x->y with lower bound L and upper bound R, cost C
// using standard trick with global S,T
void addEdgeLR(int x, int y, int L, int R, int cost) {
    int cap = R - L;
    if (L > 0) {
        // compensate lower bound
        addEdge(S, y, L, cost);
        addEdge(x, T, L, cost);
    }
    if (cap > 0) {
        addEdge(x, y, cap, cost);
    }
}

// SPFA to find shortest augmenting path from S to T
int parV[MAXV];  // previous vertex
int parE[MAXV];  // which edge used to enter
int distv[MAXV];
bool inQ[MAXV];

bool augment() {
    for (int i = 0; i < numV; ++i) {
        distv[i] = INF;
        parV[i] = -1;
        parE[i] = -1;
        inQ[i] = false;
    }
    distv[S] = 0;
    queue<int> q;
    q.push(S);
    inQ[S] = true;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        inQ[v] = false;
        for (int id : adj[v]) {
            if (!residual(id)) continue;
            int to = edges[id].to;
            int nd = distv[v] + edges[id].cost;
            if (nd < distv[to]) {
                distv[to] = nd;
                parV[to] = v;
                parE[to] = id;
                if (!inQ[to]) {
                    inQ[to] = true;
                    q.push(to);
                }
            }
        }
    }
    if (parV[T] == -1) return false;

    // push exactly 1 unit (all capacities are small, this is fine)
    int cur = T;
    while (cur != S) {
        int eid = parE[cur];
        edges[eid].flow++;
        edges[eid ^ 1].flow--;
        cur = parV[cur];
    }
    return true;
}

void addRBEdge(int left, int right) {
    // left part: 0..n1-1
    // right part: n1 .. n1+n2-1
    int L = left;
    int R = right + n1;
    // choosing red: L -> R, cost rCost
    addEdge(L, R, 1, rCost);
    // choosing blue: R -> L, cost bCost
    addEdge(R, L, 1, bCost);
}

void imposeLeft(int x) {
    // vertex x in left part
    if (sL[x] == 'R') {
        // #red - #blue >= 1 -> flow constraint oldS -> x
        addEdgeLR(oldS, x, 1, m, 0);
    } else if (sL[x] == 'B') {
        // #blue - #red >= 1 -> x -> oldT
        addEdgeLR(x, oldT, 1, m, 0);
    } else {
        // uncolored: no restriction
        addEdge(oldS, x, m, 0);
        addEdge(x, oldT, m, 0);
    }
}

void imposeRight(int x) {
    // vertex x in right part, actual node index is x + n1
    int node = x + n1;
    if (sR[x] == 'R') {
        // #red - #blue >= 1 for right vertex
        addEdgeLR(node, oldT, 1, m, 0);
    } else if (sR[x] == 'B') {
        addEdgeLR(oldS, node, 1, m, 0);
    } else {
        // uncolored
        addEdge(oldS, node, m, 0);
        addEdge(node, oldT, m, 0);
    }
}

void buildBal() {
    memset(bal, 0, sizeof(bal));
    for (int i = 0; i < n1; ++i) {
        for (int id : adj[i]) {
            int to = edges[id].to;
            if (to >= n1 && to < n1 + n2) {
                // edge between left i and right (to-n1)
                bal[i][to - n1] += edges[id].flow;
            }
        }
    }
}

bool checkFeasibleAndPrint() {
    // check that no edge out of S (the artificial source) has residual capacity
    for (int id : adj[S]) {
        if (residual(id)) {
            cout << -1 << '\n';
            return false;
        }
    }

    buildBal();

    long long totalCost = 0;
    string ans;
    ans.reserve(m);

    for (int i = 0; i < m; ++i) {
        int a = U[i];
        int b = Vv[i];
        if (bal[a][b] > 0) {
            // red chosen here
            bal[a][b]--;
            totalCost += rCost;
            ans.push_back('R');
        } else if (bal[a][b] < 0) {
            // blue chosen here (flow from right->left)
            bal[a][b]++;
            totalCost += bCost;
            ans.push_back('B');
        } else {
            ans.push_back('U');
        }
    }

    cout << totalCost << '\n';
    cout << ans << '\n';
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n1 >> n2 >> m >> rCost >> bCost;
    cin >> sL >> sR;

    for (int i = 0; i < m; ++i) {
        cin >> U[i] >> Vv[i];
        --U[i];
        --Vv[i];
    }

    // node indexing:
    // left:  0 .. n1-1
    // right: n1 .. n1+n2-1
    oldS = n1 + n2;
    oldT = oldS + 1;
    S    = oldT + 1;
    T    = S + 1;
    numV = T + 1;

    // impose vertex constraints
    for (int i = 0; i < n1; ++i) imposeLeft(i);
    for (int i = 0; i < n2; ++i) imposeRight(i);

    // add all original edges (choices for R/B)
    for (int i = 0; i < m; ++i) {
        addRBEdge(U[i], Vv[i]);
    }

    // close circulation: edge oldT -> oldS with large capacity
    addEdge(oldT, oldS, 100000, 0);

    // run min-cost circulation by repeatedly augmenting from S to T
    while (augment());

    // build answer / check feasibility
    checkFeasibleAndPrint();
    return 0;
}
