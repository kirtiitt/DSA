//TC: O(4* n*m), SC: O(n*m)
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> image, int color, int inColor) {
        int delR[]= {-1, 0, 1, 0}, delC[]= {0, 1, 0, -1};
        ans[row][col]= color;
        int n= image.size(), m= image[0].size();
        for(int i=0; i<4; i++) {
            int newr= row+ delR[i], newc= col+ delC[i];
            if(newr>=0 && newc>=0 && newr<n && newc<m && image[newr][newc]==inColor && ans[newr][newc]!=color)
                dfs(newr, newc, ans, image, color, inColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inColor= image[sr][sc];
        vector<vector<int>> ans= image;
        //4 directions
        dfs(sr, sc, ans, image, color, inColor);
        return ans;
    }
};
