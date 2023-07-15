//TC: O(n+ n) traverse+ reverse, SC: O(1)
vector<int> MorrisPostOrder(Node *root) {
    vector<int> ans;
    Node *curr= root;
    while(curr) {
        if(!curr->right) {
            ans.push_back(curr->data);
            curr= curr->left;
        }
        else {
            Node *next= curr->right;
            while(next->left && next->left!= curr)
                next= next->left;
            if(!next->left) {  //no thread exists, make a thread
                next->left= curr;
                ans.push_back(curr->data);
                curr= curr->right;
            }
            else {
                next->left= NULL;  //break the thread
                curr= curr->left;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
