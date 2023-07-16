//brute force: find all permutations and store, sort and give (k-1)th as ans
//TC: O(n!)+ O(n log n)

//optimal approach: keep fixing one element one by one from the beginning and deleting from nums
//TC: O(n^2)
class Solution {
public:
    void permute (int k, int fact, string &ans, vector<int> &num) {
        ans+= to_string(num[k/fact]);
        num.erase(num.begin()+ k/fact);
        if(num.size()==0)
            return;
        permute(k%fact, fact/num.size(), ans, num);
    }
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> num;
        string ans= "";
        for(int i=1; i<n; i++) {
            fact*=i;
            num.push_back(i);
        }
        num.push_back(n);
        k= k-1;
        permute(k, fact, ans, num);
        return ans;
    }
};
