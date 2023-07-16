//sort the data first then looping- to avoid picking duplicates in further steps
//looping used because: unique elements are not given in subset and I need to return ans with no duplicates
//no equal to size base case because that is always covered by the loop
//TC: O(2^n* k), SC: O(k* x)
class Solution {
private:
    void findCombinations(int i, vector<int> c, int target, vector <vector<int>>& ans, vector<int>& ds) {
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        for(int k=i; k<c.size(); k++) {
            if(k>i & c[k]==c[k-1])
                continue;
            if(c[k]<=target) {
                ds.push_back(c[k]);
                findCombinations (k+1, c, target-c[k], ans, ds);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <vector<int>> ans;
        vector<int> ds;
        findCombinations (0, candidates, target, ans, ds);
        return ans;
    }
};
