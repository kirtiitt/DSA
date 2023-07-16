//two possiblities: pick and not pick
//TC: O(2^n *n) for power set and printing, SC: O(n)

void seq (int i, vector <int> &dp, vector <int> &A, int n) {
    if(i>=n) {
        if(dp.size()==0)
            cout<<"{}";
        for(auto i: dp)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    dp.push_back(A[i]);
    seq (i+1, dp, A, n);
    dp.pop_back();
    seq (i+1, dp, A, n);
}
