//TC: O(4^ (n*m)), SC: O(n*m) for when all boxes are visited
class Solution{
    void maze(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, map<pair<int, int>, int> &mp, string dir) {
        if(i==n-1 && j==n-1) {
            ans.push_back(dir);
            return;
        }
        if(i+1<n && m[i+1][j]==1 && mp.find({i+1, j})==mp.end()) {
            mp[{i, j}]= 1;
            maze(i+1, j, m, n, ans, mp, dir+'D');
            mp.erase({i, j});
        }
        if(j-1>-1 && m[i][j-1]==1 && mp.find({i, j-1})==mp.end()) {
            mp[{i, j}]= 1;
            maze(i, j-1, m, n, ans, mp, dir+'L');
            mp.erase({i, j});
        }
        if(j+1<n && m[i][j+1]==1 && mp.find({i, j+1})==mp.end()) {
            mp[{i, j}]= 1;
            maze(i, j+1, m, n, ans, mp, dir+'R');
            mp.erase({i, j});
        }
        if(i-1>-1 && m[i-1][j]==1 && mp.find({i-1, j})==mp.end()) {
            mp[{i, j}]= 1;
            maze(i-1, j, m, n, ans, mp, dir+'U');
            mp.erase({i, j});
        }
    }
    public:
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        map<pair<int, int>, int> mp;
        if(m[0][0])
            maze(0, 0, m, n, ans, mp, "");
        return ans;
    }
};

