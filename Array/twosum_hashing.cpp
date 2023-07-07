//brute force: nums[i] is one elemnet, search for target- nums[i] in remaining
//TC: O(n^2), SC: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //optimized: if target- nums[i] is not found, insert element in hash table
        //TC: O(n), SC: O(n)
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            if(mp.find(target-nums[i]) != mp.end()) {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};
