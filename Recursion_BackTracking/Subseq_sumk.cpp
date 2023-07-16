//TC: O(2^n* n), SC: O(n)
void seq (int i, vector <int> &dp, vector <int> &A, int n, int s, int sum) {
    if(i>=n) {
        if(s==sum) {
            for(auto i: dp)
                cout<<i<<" ";
            cout<<endl;
        }
        return;
    }
    dp.push_back(A[i]);
    s+= A[i];
    seq (i+1, dp, A, n, s, sum);
    dp.pop_back();
    s-= A[i];
    seq (i+1, dp, A, n, s, sum);
}
