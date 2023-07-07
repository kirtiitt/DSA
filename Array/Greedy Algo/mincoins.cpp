//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    //observations: can't use greater than n in coins array, pick the max value in coins as many times as possible, when not possible decrease in coins
    //why greedy? in coins array the sum of any 2 values is less than 3rd if it was not the case then use dynamic programming
    //TC: O(n), SC: O(1)
    vector<int> minPartition(int N) {
        int size= 10, coins[]= {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;
        for(int i=size-1; i>=0 && N!=0; i--)
            while(N>= coins[i]) {
                N-= coins[i];
                ans.push_back(coins[i]);
            }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
