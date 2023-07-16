//TC: O(2^n), SC: O(2^n)
//print all subsets sum
void func (int i, vector<int> A, int n, int sum, vector<int> &Sum) {
    if(i==n) {
        Sum.push_back(sum);
        return;
    }
    func(i+1, A, n, sum+A[i], Sum);
    func(i+1, A, n, sum, Sum);
}
