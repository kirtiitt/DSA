//TC: O(n), SC: O(1)
vector<int> MorrisPreOrder(Node *root) {
    vector<int> ans;
    Node *curr= root;
    while(curr) {
        if(!curr->left) {
            ans.push_back(curr->data);
            curr= curr->right;
        }
        else {
            Node *next= curr->left;
            while(next->right && next->right!= curr)
                next= next->right;  //find rightmost node in left subtree
            if(!next->right) {  //no thread exists, make a thread
                next->right= curr;
                ans.push_back(curr->data);
                curr= curr->left;   //traverse left subtree
            }
            else {
                next->right= NULL;  //break the thread
                curr= curr->right;  //traverse right subtree
            }
        }
    }
    return ans;
}
