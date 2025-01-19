// Not working

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> visited(grid.size()*grid[0].size(),0) ;
        vector<int> q ;
        int curr,count = 0,n = grid.size()*grid[0].size();
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == 2){
                    q.push_back(i*grid[0].size()+j);  // vertex : i*grid[0].size()+j
                    visited[i*grid[0].size()+j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int siz = q.size();
            for(int i = 0 ; i < siz ; i++){
                curr = q.front();
                q.erase(q.begin());
                // grid[curr/grid[0].size()][curr%grid[0].size()];
                if (curr/grid[0].size()+1 < grid.size() && visited[(curr/grid[0].size()+1)*grid[0].size()+(curr%grid[0].size())] == 0){
                    grid[curr/grid[0].size()+1][curr%grid[0].size()] = 2;
                    visited[(curr/grid[0].size()+1)*grid[0].size()+(curr%grid[0].size())] = 1;
                    q.push_back((curr/grid[0].size()+1)*grid[0].size()+(curr%grid[0].size()));
                }
                if (curr%grid[0].size()+1 < grid[0].size() && visited[(curr/grid[0].size())*grid[0].size()+(curr%grid[0].size()+1)] == 0){
                    grid[curr/grid[0].size()][curr%grid[0].size()+1] = 2;
                    visited[(curr/grid[0].size())*grid[0].size()+(curr%grid[0].size()+1)] = 1;
                    q.push_back((curr/grid[0].size())*grid[0].size()+(curr%grid[0].size()+1));
                }
                if (curr/grid[0].size()-1 >= 0 && visited[(curr/grid[0].size()-1)*grid[0].size()+(curr%grid[0].size())] == 0){
                    grid[curr/grid[0].size()-1][curr%grid[0].size()] = 2;
                    visited[(curr/grid[0].size()-1)*grid[0].size()+(curr%grid[0].size())] = 1;
                    q.push_back((curr/grid[0].size()+1)*grid[0].size()+(curr%grid[0].size()));
                }
                if (curr%grid[0].size()-1 >= 0 && visited[(curr/grid[0].size()+1)*grid[0].size()+(curr%grid[0].size()-1)] == 0){
                    grid[curr/grid[0].size()][curr%grid[0].size()-1] = 2;
                    visited[(curr/grid[0].size())*grid[0].size()+(curr%grid[0].size()-1)] = 1;
                    q.push_back((curr/grid[0].size())*grid[0].size()+(curr%grid[0].size()-1));
                }

            }
            count++;
        }
        return count;
    }
};
