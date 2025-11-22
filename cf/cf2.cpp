#include <bits/stdc++.h>
using namespace std;

// Dinic's algorithm for Max Flow
struct Edge {
    int to;
    long long cap;
    int rev;
};

struct Dinic {
    int N;
    vector<vector<Edge>> G;
    vector<int> level;
    vector<int> prog;

    Dinic(int n) : N(n), G(n), level(n), prog(n) {}

    void add_edge(int fr, int to, long long cap) {
        Edge fwd = {to, cap, (int)G[to].size()};
        Edge rev = {fr, 0,   (int)G[fr].size()};
        G[fr].push_back(fwd);
        G[to].push_back(rev);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto &e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    long long dfs(int v, int t, long long f) {
        if (!f || v == t) return f;
        for (int &i = prog[v]; i < (int)G[v].size(); ++i) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                long long d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    long long max_flow(int s, int t) {
        long long flow = 0, inf = (long long)1e18;
        while (bfs(s, t)) {
            fill(prog.begin(), prog.end(), 0);
            long long f;
            while ((f = dfs(s, t, inf)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // Store edges as (odd_index, even_index)
    vector<pair<int,int>> edges;
    edges.reserve(m);
    for (int k = 0; k < m; ++k) {
        int x, y;
        cin >> x >> y;
        int odd = (x % 2 ? x : y);
        int even = (x % 2 ? y : x);
        edges.push_back({odd, even});
    }

    // prime -> vector of exponents per index (1..n)
    // we will allocate vectors of size n+1 when first seen
    unordered_map<long long, vector<int>> primeCnt;

    // Factorize each a[i]
    for (int i = 1; i <= n; ++i) {
        long long x = a[i];
        for (long long p = 2; p * p <= x; ++p) {
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    ++cnt;
                }
                if (!primeCnt.count(p)) {
                    primeCnt[p] = vector<int>(n + 1, 0);
                }
                primeCnt[p][i] += cnt;
            }
        }
        if (x > 1) { // x is prime
            long long p = x;
            if (!primeCnt.count(p)) {
                primeCnt[p] = vector<int>(n + 1, 0);
            }
            primeCnt[p][i] += 1;
        }
    }

    long long answer = 0;
    const long long INF = (long long)1e9; // large enough

    // For each distinct prime, build a flow network and compute max flow
    for (auto &kv : primeCnt) {
        // kv.first is the prime, kv.second is vector<int> exponents[1..n]
        auto &cnt = kv.second;

        // Quick check: if all exponents are 0 or only one side has prime, skip
        int totalExp = 0;
        for (int i = 1; i <= n; ++i) totalExp += cnt[i];
        if (totalExp <= 1) continue;

        int S = 0;
        int T = n + 1;
        Dinic dinic(n + 2);

        // Connect source to odd indices, even indices to sink
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) continue;
            if (i % 2 == 1) {
                // odd index: S -> i
                dinic.add_edge(S, i, cnt[i]);
            } else {
                // even index: i -> T
                dinic.add_edge(i, T, cnt[i]);
            }
        }

        // Edges between odd and even indices (good pairs), capacity INF
        for (auto &e : edges) {
            int odd = e.first;
            int even = e.second;
            // odd -> even
            dinic.add_edge(odd, even, INF);
        }

        long long flow = dinic.max_flow(S, T);
        answer += flow;
    }

    cout << answer << "\n";

    return 0;
}
