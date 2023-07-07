class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //same as foursum, first sort then 1 pointer and then left, right for the remaining 2 elements
        //TC: O(n^2), SC: O(1)
        vector<vector<int>> ans;
        if(nums.empty())  return ans;
        sort(nums.begin(), nums.end());
        int n= nums.size(), i= 0;
        while(i<n) {
            long long sum= (long long)0- (long long)nums[i];  //0 is the target
            int left= i+1, right= n-1;
            while(left< right) {
                long long subsum= (long long)nums[left]+ (long long)nums[right];
                if(subsum> sum)  right--;
                else if(subsum< sum)  left++;
                else {
                    vector<int> sub;
                    sub.push_back(nums[i]);
                    sub.push_back(nums[left]);
                    sub.push_back(nums[right]);
                    ans.push_back(sub);
                    while(left<right && nums[left]== sub[1])  left++;
                    while(left<right && nums[right]== sub[2])  right--;
                }
            }
            while(++i<n && nums[i]== nums[i-1]);
        }
        return ans;
    }
};
