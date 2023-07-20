//TC: O(n* m)+ O(4* n* m), SC: O(n* m)+ O(n* m)
class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col]= 1;
        int n= grid.size(), m= grid[0].size();
        int delR[]= {-1, 0, 1, 0}, delC[]= {0, 1, 0, -1};
        while(!q.empty()) {
            row= q.front().first;
            col= q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int newr= row+ delR[i], newc= col+ delC[i];
                if(newr>=0&& newc>=0&& newr<n&& newc<m&& grid[newr][newc]=='1'&& !vis[newr][newc]) {
                    vis[newr][newc]= 1;
                    q.push({newr, newc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count= 0;
        int n= grid.size(), m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] && grid[i][j]=='1') {
                    count++;
                    bfs(i, j, grid, vis);
                }
        return count;
    }
};
