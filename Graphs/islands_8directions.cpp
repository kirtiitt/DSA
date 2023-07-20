//TC: O(n*m)+ O(8* n*m), SC: O(n*m)+ O(n*m)
class Solution {
  private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid) {
        vis[row][col]= 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n= grid.size(), m= grid[0].size();
        while(!q.empty()) {
            row= q.front().first;
            col= q.front().second;
            q.pop();
            for(int delr=-1; delr<=1; delr++)
                for(int delc=-1; delc<=1; delc++) {
                    int newr= row+ delr;
                    int newc= col+ delc;
                    if(newr>=0 && newc>=0 && newr<n && newc<m && !vis[newr][newc]&& grid[newr][newc]=='1') {
                        vis[newr][newc]= 1;
                        q.push({newr, newc});
                    }
                }
        }
    }
    
  public:
    int numIslands(vector<vector<char>> &grid) {
        int n= grid.size(), m= grid[0].size();
        vector<vector<int>> vis (n, vector<int>(m,0));
        int count= 0;
        //bfs traversal- 8 directions (all neighbours)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] && grid[i][j]=='1') {
                    count++;
                    bfs(i, j, vis, grid);
                }
        return count;
    }
};
