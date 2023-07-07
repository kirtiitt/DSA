//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    //todo: max value, sort struct acc to value per weight
    //greedy algo: pick the whole weight till capacity available and then pick fractional weight
    //TC: O(nlogn+ n), SC: O(1)
    public:
        static bool comp(Item i1, Item i2) {
            double vperw1= i1.value/ (double)i1.weight;
            double vperw2= i2.value/ (double)i2.weight;
            return (vperw1> vperw2);
        }
        
        double fractionalKnapsack(int W, Item arr[], int n) {
            sort(arr, arr+n, comp);
            int usedw= 0;
            double ansvalue= 0.0;
            for(int i=0; i<n; i++) {
                if(usedw+ arr[i].weight<= W) {
                    usedw+= arr[i].weight;
                    ansvalue+= arr[i].value;
                }
                else {
                    double vperw= arr[i].value/ (double)arr[i].weight;
                    ansvalue+= (W- usedw)* vperw;   //available capacity* value per weight
                    break;
                }
            }
            return ansvalue;
        }
};
