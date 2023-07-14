class Solution {
public:
    //TC for heapify: O(log n)
    void heapify(vector<int> &A, int size, int i) {
        int largest= i, left= 2*i+ 1, right= 2*i+ 2;
        if(left<size && A[left]> A[largest])
            largest= left;
        if(right<size && A[right]> A[largest])
            largest= right;
        if(largest!= i) {
            swap(A[largest], A[i]);
            heapify(A, size, largest);
        }
    }

    //TC for build heap: O(n)
    void buildHeap(vector<int> &A, int size) {
        for(int i=(size/2-1); i>=0; i--)
            heapify(A, size, i);
    }

    //TC: O(n* log n) for heap sort
    vector<int> sortArray(vector<int>& nums) {
        int size= nums.size();
        buildHeap(nums, size);
        while(size) {
            swap(nums[0], nums[size-1]);
            size--;
            heapify(nums, size, 0);
        }
        return nums;
    }
};
