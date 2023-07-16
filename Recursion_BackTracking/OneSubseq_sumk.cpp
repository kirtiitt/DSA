bool seq (int i, vector <int> &dp, vector <int> &A, int n, int s, int sum) {
    if(i>=n) {
        if(s==sum) {
            for(auto i: dp)
                cout<<i<<" ";
            cout<<endl;
        return true;
        }
        return false;
    }
    dp.push_back(A[i]);
    s+=A[i];
    if (seq (i+1, dp, A, n, s, sum)== true)
        return true;
    dp.pop_back();
    s-=A[i];
    if (seq (i+1, dp, A, n, s, sum)== true)
        return true;
    return false;
}
