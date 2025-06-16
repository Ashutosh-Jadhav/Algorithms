// initial Approach

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n,m,u,flag=0 ; n = wordList.size() ; m = beginWord.size() ;
        wordList.push_back(beginWord);
        vector<int> visited(n+1,0);    // nth is beginword
        vector<int> c(n+1,0);
        queue<int> q;
        q.push(n); visited[n] = 1; c[n] = 1 ;
        while(!q.empty()) {
            u = q.front(); q.pop();
            for (int i= 0; i < n ; i++) {
                if (!visited[i]) {
                    for (int j = 0 ; j < m ; j++) {
                        if (wordList[u][j] != wordList[i][j]) flag++;
                        if (flag > 1) break;
                    }
                    if (flag == 1) {
                        c[i] = c[u] + 1;
                        q.push(i);
                        visited[i] =1 ;
                    }
                    flag=0;
                }
            }
        }
        auto it = find(wordList.begin() , wordList.end() , endWord);
        int idx = distance(wordList.begin() , it);
        // for (int i= 0 ; i < n ; i++) cout << visited[i] << endl;
        if (idx >= n) return 0;
        return c[idx];
    }
};