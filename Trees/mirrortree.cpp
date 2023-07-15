/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

//TC: O(n)
class Solution {
  public:
    void mirror(Node* node) {
        Node *temp= node->left;
        node->left= node->right;
        node->right= temp;
        if(node->left)  mirror(node->left);
        if(node->right)  mirror(node->right);
    }
};
