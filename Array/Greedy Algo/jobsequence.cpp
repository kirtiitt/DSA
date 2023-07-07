/*
struct Job
{
    int id;     // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
    //todo: max profit, sort given struct acc to max profit (desc order of profit)
    //intuition: perform each job on deadline, if deadline not available then subtract and finish job early
    //TC: O(nlogn)+ O(n*m) (n for job, m for max deadline), SC: O(m)
    public:
        static bool comp(Job j1, Job j2) {
            return (j1.profit> j2.profit);
        }
        
        vector<int> JobScheduling(Job arr[], int n)  {
            sort(arr, arr+n, comp);
            int maxdead= 0;
            for(int i=0; i<n; i++)
                maxdead= max(maxdead, arr[i].dead);
            int slots[maxdead+1];
            for(int i=0; i<=maxdead; i++)
                slots[i]= -1;
            int jobs= 0, profit= 0;
            for(int i=0; i<n; i++)
                for(int j=arr[i].dead; j>0; j--)   //traverse for checking empty slot in slots array
                    if(slots[j]==-1) {
                        slots[j]= i;
                        jobs++;
                        profit+= arr[i].profit;
                        break;
                    }
            vector<int> ans= {jobs, profit};
            return ans;
        }
};
