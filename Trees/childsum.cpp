//root= left+ right
//every node can be increased by 1 any no. of times but no decreased
//if we start going down in a tree and keep updating the nodes, problem will occur for leaf nodes and similarly for upward movement problem will occur for root
//go left, right and then return to root
//TC: O(n), SC: O(n)
void findChild (Node *root) {
    if(!root)   return;
    int child= 0;
    if(root->left)
        child+= root->left->data;
    if(root->right)
        child+= root->right->data;
    if(child>= root->data)
        root->data= child;
    else {
        if(root->left)
            root->left->data= root->data;
        else if(root->right)    //update only one child instead of both, can do both also tho
            root->right->data= root->data;
    }
    findChild(root->left);
    findChild(root->right);
    //now update root
    int sum= 0;
    if(root->left) {
        sum+= root->left->data;
        root->data= sum;
    }
    if(root->right) {
        sum+= root->right->data;
        root->data= sum;
    }
}
