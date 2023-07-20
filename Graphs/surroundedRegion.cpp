//TC: O(n)+ O(n* m)+ O(4* n* m), SC: O(n* m)+ O(n* m)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size(), m= board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        //push the boundary O in queue
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(i==0|| j==0|| i==n-1|| j==m-1)
                    if(board[i][j]=='O') {
                        vis[i][j]= 1;
                        q.push({i,j});
                    }
        int delta[]= {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            int row= q.front().first, col= q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nr= row+ delta[i], nc= col+ delta[i+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && board[nr][nc]=='O') {
                    vis[nr][nc]= 1;
                    q.push({nr, nc});
                }
            }
        }
        //change O with X
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j]=='O' && !vis[i][j]) {
                    vis[i][j]= 1;
                    board[i][j]='X';
                }
    }
};

/* another way of figuring out the boundary
for(int j=0; j<m; j++) {
    if(board[0][j]=='O') {
        vis[0][j]= 1;
        q.push({0, j});
    }
    if(board[n-1][j]=='O') {
        vis[n-1][j]= 1;
        q.push({n-1, j});
    }
}
for(int i=0; i<n; i++) {
    if(board[i][0]=='O') {
        vis[i][0]= 1;
        q.push({i, 0});
    }
    if(board[i][m-1]=='O') {
        vis[i][m-1]= 1;
        q.push({i, m-1});
    }
} */
