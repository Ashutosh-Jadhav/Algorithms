#include <bits/stdc++.h>
using namespace std ;
int main(){
    int n, m ;    // n - number of vertices , m - number of edges in graph
    cin >> n >> m ;
    // vector<vector<int>> adj(n+1,vector<int>(n+1,0));     // Adjecency matrix representation
    // for (int i = 0 ; i < m ; i++){
    //     int u,v ;
    //     cin >> u >> v ;
    //     adj[u][v] = 1 ;
    //     // adj[v][u] = 1 ;                          // comment if it is a directed graph
    // }
    // for (int i = 0 ; i < n+1 ; i++){
    //     for (int j = 0 ; j < n+1 ; j++) {
    //         cout << adj[i][j] << " " ;
    //     }
    //     cout << endl;
    // }

    // vector<int> adj[n+1] ;                              // Adjecency list
    // for (int i = 0 ; i < m ; i++) {
    //     int u,v ;
    //     cin >> u >> v ;
    //     adj[u].push_back(v) ;
    //     adj[v].push_back(u) ;                           // comment if graph is directed
    // }
    // for (int i = 1 ; i <= n ; i++){
    //     cout << "node " << i << ": " ;
    //     for (int m : adj[i]) {
    //         cout << m << " ";
    //     }
    //     cout << endl ;
    // }

    vector<pair<int,int>> edgelis;
    for (int i = 0 ; i < m ; i++ ) {
        int u,v ;
        cin >> u >> v ;
        edgelis.push_back({u,v});
        // edgelis.push_back({v,u});                      // comment if graph is directed
    }
    for (auto edge : edgelis) {
        cout << edge.first << " - " << edge.second << endl ;
    }

    return 0;
}
