//TC: O(n)
void factorial(int n) {
    if(n== 1)
        return 1;
    return n* factorial(n-1);
}

//TC: O(2^n)
void fibonacci(int n) {
    if(n<=1)
        return n;
    return fibonacci(n-1)+ fibonacci(n-2);
}
