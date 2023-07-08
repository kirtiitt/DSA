#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

//use stack to push root first and then push right first then left, so left is popped out first
//TC: O(n), SC: O(n)

vector<int> PreOrderTrav(Node *root) {
    vector<int> ans;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        struct Node *node= s.top();
        s.pop();
        ans.push_back(node->data);
        if(node->right)  s.push(node->right);
        if(node->left)  s.push(node->left);
    }
    return ans;
}

int main() {
    struct Node *root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->left->right->left= new Node(8);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->right->right->left= new Node(9);
    root->right->right->right= new Node(10);
    vector <int> ans;
    ans= PreOrderTrav(root);
    cout<<"The preorder traversal is: ";
    for(int i=0; i<ans.size(); i++)  cout<<ans[i]<<" ";
    return 0;
}
