class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x,y,n,m,st_color ; m = image.size() ; n = image[0].size();
        vector<vector<int>> v(m,vector<int> (n,0));
        queue<pair<int,int>> q ;
        q.push(make_pair(sr,sc)); st_color = image[sr][sc]; v[sr][sc] = 1 ;
        image[sr][sc] = color ;
        while(!q.empty()) {
            x = q.front().first ; y = q.front().second ;
            q.pop();
            if (x > 0 && image[x-1][y] == st_color && v[x-1][y] == 0) {
                image[x-1][y] = color ;
                q.push(make_pair(x-1,y));
                v[x-1][y] = 1;
            }
            if (x < m-1 && image[x+1][y] == st_color && v[x+1][y] == 0) {
                image[x+1][y] = color ;
                q.push(make_pair(x+1,y));
                v[x+1][y] = 1;
            }
            if (y > 0 && image[x][y-1] == st_color && v[x][y-1] == 0) {
                image[x][y-1] = color ;
                q.push(make_pair(x,y-1));
                v[x][y-1] = 1;
            }
            if (y < n-1 && image[x][y+1] == st_color && v[x][y+1] == 0) {
                image[x][y+1] = color ;
                q.push(make_pair(x,y+1));
                v[x][y+1] = 1;
            }
        }
        return image;
    }
};