#include<bits/stdc++.h>
using namespace std;

void heapify(int A[], int size, int i) {
    int largest= i, left= 2*i+ 1, right= 2*i+ 2;
    if(left<size && A[left]> A[largest])
        largest= left;
    if(right<size && A[right]> A[largest])
        largest= right;
    if(largest!= i) {
        swap(A[largest], A[i]);
        //check for the remaining heap, till leaves
        heapify(A, size, largest);
    }
}

void buildHeap(int A[], int size) {
    //0 based indexing
    for(int i=(size/2-1); i>=0; i--)
        heapify(A, size, i);
}

int main() {
    int A[7]= {1, 6, 2, 3, 4, 0, 7};
    int size= 7;
    buildHeap(A, size);
    for(int i=0; i<size; i++)
        cout<<A[i]<<" ";
    return 0;
}