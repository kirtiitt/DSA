#include<bits/stdc++.h>
using namespace std;

//max heap
class Heap {
public:
    int A[50], size;
    Heap() {
        A[0]= -1;
        size= 0;
    }

    void insert(int val) {
        size++;
        int ind= size;
        A[ind]= val;
        while(ind>1) {
            int parent= ind/2;
            if(A[parent]< A[ind]) {
                swap(A[parent], A[ind]);
                ind= parent;
            }
            else    return;
        }
    }

    void print() {
        for(int i=1; i<=size; i++)
            cout<<A[i]<<" ";
    }
};

int main() {
    Heap H;
    H.insert(60);
    H.insert(20);
    H.insert(50);
    H.insert(30);
    H.insert(40);
    H.insert(55);
    H.print();
    return 0;
}