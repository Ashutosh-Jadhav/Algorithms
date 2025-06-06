class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        queue<int> q ;
        vector<int> visited(n,0);
        vector<pair<int,int>> components;
        int u,v,n_edges = 0 , n_vertices = 0 ,n_complete_components=0;
        q.push(0); visited[0] = 1 ; n_vertices++ ;
        while(!q.empty()) {
            u = q.front() ;
            q.pop();
            for (int i = 0 ; i < edges.size() ; i++) {
                if (edges[i][0] == u) {
                    v = edges[i][1] ; n_edges++;
                    if (visited[v] == 0){
                        visited[v] = 1 ; q.push(v); n_vertices++ ; 
                    }
                }
                if (edges[i][1] == u) {
                    v = edges[i][0] ; n_edges++ ;
                    if (visited[v] == 0){
                        visited[v] = 1 ; q.push(v) ; n_vertices++;
                    }
                }
            }
            if (q.empty()) {
                components.push_back(make_pair(n_edges/2,n_vertices));
                n_edges=0;n_vertices=0;
                for (int i= 0 ; i < n ; i++) {
                    if (visited[i] == 0) {
                        q.push(i); n_vertices++;visited[i] = 1;
                        break;
                    }
                }
            }
        }
        for (int i = 0 ; i < components.size() ; i++) {
            if (components[i].first == components[i].second*(components[i].second-1)/2 ) n_complete_components++;
            cout << components[i].first << " " << components[i].second << endl;
        }
        return n_complete_components;
    }
};