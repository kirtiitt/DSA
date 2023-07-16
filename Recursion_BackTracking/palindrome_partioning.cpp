//do partioning at each break point and check if left substr is a palindrome
class Solution {
public:
    void func(int ind, string s, vector<string> &sub, vector<vector<string>> &ans) {
        if(ind==s.size()) {
            ans.push_back(sub);
            return;
        }
        for(int i= ind; i<s.size(); i++) {
            if(ispalindrome(s, ind, i)) {
                sub.push_back(s.substr(ind, i-ind+1));  //substr(index, size)
                func(i+1, s, sub, ans);
                sub.pop_back();
            }
        }
    }

    bool ispalindrome(string s, int start, int end) {
        while(start<=end)
            if(s[start++]!= s[end--])  return false;
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        func(0, s, sub, ans);
        return ans;
    }
};
