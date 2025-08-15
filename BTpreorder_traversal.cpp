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
class Solution {
public:
    void preorder(TreeNode* root,vector<int> &ans){
        if(root!=nullptr)
        {
            ans.push_back(root->val);
            preorder(root->left,ans);
            preorder(root->right,ans);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);

        return ans;
    }
};

// Moris Preorder Traversal TC: O(n)    SC:O(1)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;

        while(curr!=nullptr)
        {
            if(curr->left==nullptr)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* IP=curr->left;
                while(IP->right!=nullptr && IP->right!=curr)
                    IP=IP->right;
                
                if(IP->right==nullptr)
                {
                    IP->right=curr; //creating thread
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    IP->right=nullptr;
                    curr=curr->right;
                }
            }
        }

        return ans;
    }
};