//root and left are pushed in the stack then printed, then right is pushed
//TC: O(n), SC: O(n)

vector<int> InOrderTrav(Node *root) {
    vector<int> ans;
    stack<Node*> s;
    struct Node *node= root;
    while(true) {
        if(node) {
            //pushes all roots and left nodes, initially
            //right node is found in else and then again check for left nodes, go to else for right then again left and so on
            s.push(node);
            node=node->left;
        }
        else {
            if(s.empty())  break;
            //pops the left node first, prints it and checks for right nodes, repeats same steps for the root in next iteration, so runs 2 times in while
            node= s.top();
            s.pop();
            ans.push_back(node->data);
            node= node->right;
        }
    }
    return ans;
}
