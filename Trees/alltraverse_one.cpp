//TC: O(3n), SC: O(3n) each node is visited thrice and stored thrice with count 1, 2, 3 resp for order traversal

void Traversal (Node *root, vector<int> &pre, vector<int> &in, vector<int> &post) {
    if(root==NULL)  return;
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while(!st.empty()) {
        auto it= st.top();
        st.pop();
        if(it.second== 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left)  st.push({it.first->left, 1});
        }
        else if(it.second== 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right)  st.push({it.first->right, 1});
        }
        else
            post.push_back(it.first->data);
    }
}
