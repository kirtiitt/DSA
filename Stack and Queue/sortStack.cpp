//TC: O(n^2), SC: O(n) for the sortStack func
void insert(stack<int> &stack, int num) {
    if(stack.empty()|| num> stack.top())    stack.push(num);
    else {
        int temp= stack.top();
        stack.pop();
        insert(stack, num);
        stack.push(temp);
    }
}

void sortStack(stack<int> &stack) {
    if(stack.empty())
        return;
    int num= stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, num);
}
