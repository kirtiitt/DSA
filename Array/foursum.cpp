//brute force: sort, (3 pointer) for i=0, for j=i+1, for k=j+1, binary search for 4th element then check for unique sets
//TC: O(nlogn+ n^3logn), SC: O(n) for storing ans and checking of unique quads

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //optimized: sort, 2 pointer and then left, right for the last 2 elements (not binary search)
        //TC: O(n^3), SC: O(1)
        vector<vector<int>> ans;
        if(nums.empty())  return ans;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<n) {
            int j=i+1;
            while(j<n) {
                long long t2= target- (long long)nums[i]- (long long)nums[j];
                int left= j+1, right= n-1;
                while(left< right) {
                    long long sum= (long long)nums[left]+ (long long)nums[right];
                    if(sum< t2)  left++;
                    else if(sum> t2)  right--;
                    else {
                        vector<int> quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[left]);
                        quad.push_back(nums[right]);
                        ans.push_back(quad);
                        while(left<right && nums[left]==quad[2])  ++left;
                        while(left<right && nums[right]==quad[3])  --right;
                    }
                }
                while(++j<n && nums[j]==nums[j-1]);
            }
            while(++i<n && nums[i]==nums[i-1]);
        }
        return ans;
    }
};
