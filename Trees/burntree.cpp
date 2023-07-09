//using BFS- level order
//TC: O(n)+ O(n), SC: approx O(n)
class Solution {
    Node* findParents(Node* root, unordered_map<Node*, Node*> &parent, int start) {
        Node* ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* node= q.front();
            q.pop();
            if(start== node->data)  ans= node;
            if(node->left) {
                parent[node->left]= node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right]= node;
                q.push(node->right);
            }
        }
        return ans;
    }
    
public:
    int minTime(Node* root, int start) {
        unordered_map<Node*, Node*> parent;
        Node* target= findParents(root, parent, start);
        unordered_map<Node*, int> visited;
        queue<Node*> q;
        q.push(target);
        visited[target]= 1;
        int count= 0;
        while(!q.empty()) {
            int size= q.size();
            for(int i=0; i<size; i++) {
                Node* node= q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left]= 1;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right]= 1;
                }
                if(parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]]= 1;
                }
            }
            count++;
        }
        return count- 1;  //when burning the leaf nodes, an extra iteration runs for NULL, that's why subtract 1
    }
};

//using DFS
//max height from target is found in left, right and parent direction and that is the ans
class Solution {
    Node* findParents(Node* root, unordered_map<Node*, Node*> &parent, int start) {
        Node* ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* node= q.front();
            q.pop();
            if(start== node->data)  ans= node;
            if(node->left) {
                parent[node->left]= node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right]= node;
                q.push(node->right);
            }
        }
        return ans;
    }
  
    int traverse(Node *root, unordered_map<Node*, Node*> &parent,
                    unordered_map<Node*, int> &visited) {
        if(!root)   return 0;
        visited[root]= 1;
        int lh= 0, rh= 0, ph= 0;
        if(!visited[root->left])
            lh= traverse(root->left, parent, visited);
        if(!visited[root->right])
            rh= traverse(root->right, parent, visited);
        if(!visited[parent[root]])
            ph= traverse(parent[root], parent, visited);
        return max(ph, max(lh, rh))+ 1;
    }
  
public:
    int minTime(Node* root, int start) {
        unordered_map<Node*, Node*> parent;
        Node* target= findParents(root, parent, start);
        unordered_map<Node*, int> visited;
        int height= traverse(target, parent, visited);
        return height- 1;  //same reason as why you did -1 in BFS
    }
};
