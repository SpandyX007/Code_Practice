/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void findPre(Node* root,int key,vector<Node*>& ans){
        Node* Pre=nullptr;
        Node* curr=root;
        while(curr!=nullptr)
        {
            if(curr->data<key)
            {
                Pre=curr;
                curr=curr->right;
            }
            else
                curr=curr->left;
        }
        ans.push_back(Pre);
    }
    
    void findSuc(Node* root,int key,vector<Node*>& ans){
        Node* Suc=nullptr;
        Node* curr=root;
        while(curr!=nullptr)
        {
            if(curr->data<=key)
                curr=curr->right;
            else
            {
                Suc=curr;
                curr=curr->left;
            }
        }
        ans.push_back(Suc);
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans;
        if(root==nullptr)
            return ans;
        findPre(root,key,ans);
        findSuc(root,key,ans);
        return ans;
    }
};