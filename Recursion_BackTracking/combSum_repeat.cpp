//intuition: pick and not pick but stay on same index if picking and next index if not picking
//TC: O(2^t *k), SC: O(k* x) for storing in ans
class Solution {
private:
    void findCombinations (int i, vector<int> A, int target, vector <vector<int>> &ans, vector<int> &ds) {
        if(i==A.size()) {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(A[i]<=target) {
            ds.push_back(A[i]);
            findCombinations (i, A, target-A[i], ans, ds);
            ds.pop_back();
        }
        findCombinations (i+1, A, target, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ans, ds);
        return ans;
    }
};
