/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Naive solution TC:O(n)    SC:O(n)
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& intrav){
        if(root!=nullptr)
        {
            inorder(root->left,intrav);
            intrav.push_back(root->val);
            inorder(root->right,intrav);
        }
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> intrav;
        inorder(root,intrav);
        for(int i=0;i<intrav.size()-1;i++)
        {
            if(intrav[i]>=intrav[i+1])
                return false;
        }
        return true;
    }
};



// TC: O(n)     SC:O(1)
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& intrav){
        // using morris inorder traversal
        TreeNode* curr=root;
        while(curr!=nullptr)
        {
            if(curr->left==nullptr)
            {
                intrav.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* IP=curr->left;
                while(IP->right!=nullptr && IP->right!=curr)
                    IP=IP->right;
                if(IP->right==nullptr)
                {
                    IP->right=curr;
                    curr=curr->left;
                }
                else
                {
                    IP->right=nullptr;
                    intrav.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> intrav;
        inorder(root,intrav);
        for(int i=0;i<intrav.size()-1;i++)
        {
            if(intrav[i]>=intrav[i+1])
                return false;
        }
        return true;
    }
};