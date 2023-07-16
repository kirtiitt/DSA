//using 2 pointers
//TC: O(n/2)
void reverse(int A[], int l, int r) {
    if(l>=r)
        return;
    swap(A[l], A[r]);
    reverse(A, l+1, r-1);
}

//using 1 pointer
//TC: O(n/2)
void reverse(int A[], int i, int n) {
    if(i>=n/2)
        return;
    swap(A[i], A[n-i-1]);
    reverse(A, i+1, n);
}

//palindrome- 1 pointer
//TC: O(n/2)
bool palindrome(int A[], int i, int n) {
    if(i>= n/2)
        return true;
    if(A[i]!= A[n-i-1])
        return false;
    return palindrome(A, i+1, n);
}
