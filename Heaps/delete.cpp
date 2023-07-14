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

    //it's always deletion of root we're talking about
    void deletee() {
        if(!size) {
            cout<<"Empty heap";
            return;
        }
        A[1]= A[size];
        size--;
        //compare with children and swap
        for(int i=1; i<size; ) {
            int leftind= 2* i, rightind= 2* i+ 1;
            if(leftind<= size && A[i]< A[leftind] && A[leftind]> A[rightind]) {
                swap(A[i], A[leftind]);
                i= leftind;
            }
            else if(rightind<= size && A[i]< A[rightind] && A[rightind]> A[leftind]) {
                swap(A[i], A[rightind]);
                i= rightind;
            }
            else    return;
        }
    }
};

int main() {
    Heap H;
    H.insert(73);
    H.insert(53);
    H.insert(63);
    H.insert(52);
    H.insert(50);
    H.print();
    H.deletee();
    cout<<endl;    H.print();
    return 0;
}