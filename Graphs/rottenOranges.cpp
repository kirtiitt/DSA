//TC: O(n*m)+ O(4*n*m), SC: O(n*m)+ O(n*m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        //calculate time with q because each 2 simultaneously is rotting and one may take more time than other
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count= 0, countRot= 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) {
                if(grid[i][j]==2) {
                    q.push({{i, j}, 0});
                    vis[i][j]= 1;
                }
                if(grid[i][j]==1)   count++;
            }
        int time= 0;
        int delR[]= {-1, 0, 1, 0}, delC[]= {0, 1, 0, -1};
        while(!q.empty()) {
            int row= q.front().first.first, col= q.front().first.second;
            int t= q.front().second;
            time= max(time, t);
            q.pop();
            for(int i=0; i<4; i++) {
                int newr= row+ delR[i], newc= col+ delC[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc]==1 && !vis[newr][newc]) {
                    vis[newr][newc]= 1;
                    q.push({{newr, newc}, t+1});
                    countRot++;
                }
            }
        }
        //if not all oranges are rotten
        if(count!= countRot)
            return -1;
        return time;
    }
};
