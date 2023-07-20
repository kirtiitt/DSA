//TC: O(n* m)+ O(4* n* m), SC: O(n* m)+ O(n* m)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size(), m= mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair <pair<int, int>, int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mat[i][j]==0) {
                    vis[i][j]= 1;
                    q.push({{i, j}, 0});
                }
        int delta[]= {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            int row= q.front().first.first, col= q.front().first.second;
            int dist= q.front().second;
            q.pop();
            ans[row][col]= dist;
            for(int i=0; i<4; i++) {
                int newr= row+ delta[i], newc= col+ delta[i+1];
                if(newr>=0 && newc>=0 && newr<n && newc<m && !vis[newr][newc]&& mat[newr][newc]!=0) {
                    vis[newr][newc]= 1;
                    q.push({{newr, newc}, dist+1});
                }
            }
        }
        return ans;
    }
};
