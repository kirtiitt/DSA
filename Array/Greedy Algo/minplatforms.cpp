//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    //greedy algorithm
    //sort arrival and departure array individually, new platform req if arr[current]<= dep[prev] and platform becomes vacant when arr[current]> dep[prev] then calculate max
    //TC: O(2nlogn) (sort 2 arrays)+ O(2n)-> (for worst case where new platform is needed for every train), SC: O(1)
    public:
        int findPlatform(int arr[], int dep[], int n) {
            sort(arr, arr+n);
            sort(dep, dep+n);
            int platf= 1, count= 1, i= 0, j= 1;
            //i for departure and j for arrival
            while(i<n && j<n) {
                if(arr[j]<= dep[i]) {
                    platf++;
                    j++;
                }
                else if(arr[j]> dep[i]) {
                    platf--;
                    i++;
                }
                count= max(platf, count);
            }
            return count;
        }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    }
   return 0;
}
// } Driver Code Ends
