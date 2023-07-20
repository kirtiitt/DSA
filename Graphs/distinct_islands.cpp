//TC: O(n* m)+ O(4* n* m* log(n*m)) log for set, SC: O(n* m)+ O(n* m)+ O(n* m) for vis, shape and stack space
class Solution {
  private:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m, int i, int j, vector<pair<int, int>> &shape) {
        vis[r][c]=1;
        shape.push_back({r-i, c-j});
        int del[]= {-1, 0, 1, 0, -1};
        for(int k=0; k<4; k++) {
            int nr= r+ del[k], nc= c+ del[k+1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                dfs(nr, nc, vis, grid, n, m, i, j, shape);
        }
    }
  
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int, int>>> s;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] && grid[i][j]==1) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, vis, grid, n, m, i, j, shape);
                    s.insert(shape);
                }
        return s.size();
    }
};
