/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

// in this we are traversing left boundary first, then leafs then right

bool isLeaf(Node* root){
    return (!root->left && !root->right);
}

void addLeftBoundary(Node* root, vector<int>& ans){
    Node* curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr))
            ans.push_back(curr->data);
        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}

void addLeaves(Node* root, vector<int>& ans){
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaves(root->left, ans);
    if(root->right)
        addLeaves(root->right, ans);
}

void addRightBoundary(Node* root, vector<int>& ans){
    Node* curr=root->right;
    vector<int> temp;   //this is used to store the right boundary in reverse order
    while(curr)
    {
        if(!isLeaf(curr))
            temp.push_back(curr->data);
        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--)     //for the storing in 'ans' in reverse
        ans.push_back(temp[i]);
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        if(!isLeaf(root))
            ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeaves(root,ans);
        addRightBoundary(root,ans);
        
        return ans;
    }
};