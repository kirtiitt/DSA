//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    //this is same as ACTIVITY SELECTION
    //store position of activity, start time, finish time in a data structure (struct, vector etc) then sort acc to finishing time (if same acc position) and use greedy approach
    //TC: O(n)+ O(nlogn)+ O(n), SC: O(n) for struct
    struct meeting {
        int st, fin, pos;
    };
    
    static bool comp(struct meeting m1, struct meeting m2) {
        if(m1.fin< m2.fin)   return true;
        else if(m1.fin> m2.fin)   return false;
        else if(m1.pos< m2.pos)   return true;
        return false;
    }
    
    public:
        int maxMeetings(int start[], int end[], int n) {
            struct meeting m[n];
            for(int i=0; i<n; i++) {
                m[i].st= start[i];
                m[i].fin= end[i];
                m[i].pos= i+1;   //required if order of activity needs to be printed like 1, 2 etc
            }
            sort(m, m+n, comp);
            int limit= m[0].fin;
            int count= 1;
            for(int i=1; i<n; i++)
                if(m[i].st> limit) {
                    count++;
                    limit= m[i].fin;
                }
            return count;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
