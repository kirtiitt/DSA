//TC: O(2^n)
int seq (int i, vector <int> &A, int n, int s, int sum) {
    if(i==n) {
        if(s==sum)
            return 1;
        return 0;
    }
    int l= seq (i+1, A, n, s+A[i], sum);
    int r= seq (i+1, A, n, s, sum);
    return l+r;
}
