//push in stack such that ans contains an order: root, right, left so when reverse takes place ans contains L, R, Root
//TC: O(n)+ O(n), SC: O(n)

vector<int> PostOrderTrav(Node* root) {
    vector<int> ans;
    stack<Node*> s1;
    s1.push(root);
    while(!s1.empty()) {
        Node *node= s1.top();
        s1.pop();
        ans.push_back(node->data);
        if(node->left)  s1.push(node->left);
        if(node->right)  s1.push(node->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
