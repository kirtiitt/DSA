class Solution {
public:
    //time limit exceeded in some cases for dfs- because 4 directions traversed in depth one by one by dfs and in bfs, 4 directions simultaneously
    /* void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> grid, int n, int m) {
        vis[row][col]= 1;
        int delta[]= {-1, 0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int nr= row+ delta[i], nc= col+ delta[i+1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                dfs(nr, nc, vis, grid, n, m);
        }
    } */

    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int j=0; j<m; j++) {
            if(grid[0][j]==1){
                vis[0][j]= 1;
                q.push({0, j});
            }
            if(grid[n-1][j]==1){
                vis[n-1][j]= 1;
                q.push({n-1, j});
            }
        }
        for(int i=0; i<n; i++) {
            if(grid[i][0]==1){
                vis[i][0]= 1;
                q.push({i, 0});
            }
            if(grid[i][m-1]==1){
                vis[i][m-1]= 1;
                q.push({i, m-1});
            }
        }
        int delta[]= {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            int row= q.front().first, col= q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nr= row+ delta[i], nc= col+ delta[i+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1) {
                    vis[nr][nc]= 1;
                    q.push({nr, nc});
                }
            }
        }
        int count= 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] && grid[i][j]==1)
                    count++;
        return count;
    }
};
