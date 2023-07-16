//approach: using hash to mark picked up elements and then unmarking
//TC: O(n!) *O(n), SC: O(n)+ O(n)
class Solution {
private:
    void findPerm (vector<int> nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &freq) {
        if(ds.size()==nums.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!freq[i]) {
                ds.push_back(nums[i]);
                freq[i]=1;
                findPerm (nums, ds, ans, freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n= nums.size();
        vector<int> freq(n, 0);
        findPerm (nums, ds, ans, freq);
        return ans;
    }
};

//approach 2: swapping
//TC: O(n!) *O(n), auxiliary SC: O(n)
class Solution {
private:
    void findPermute (int ind, vector<int> nums, vector<vector<int>> &ans) {
        if(ind==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++) {
            swap(nums[ind], nums[i]);
            findPermute (ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermute (0, nums, ans);
        return ans;
    }
};
