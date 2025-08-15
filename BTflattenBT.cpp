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

// Stack based approach
// TC: O(n)     SC: O(n)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return;

        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr=s.top();
            s.pop();
            if(curr->right)
                s.push(curr->right);
            if(curr->left)
                s.push(curr->left);
            if(!s.empty())
                curr->right=s.top();
            curr->left=nullptr;
        }
    }
};

// Using Morris Preorder Traversal
// TC: O(n)     SC:O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return;
        
        TreeNode* curr=root;
        while(curr!=nullptr)
        {
            if(curr->left!=nullptr)
            {
                TreeNode* IP=curr->left;
                while(IP->right!=nullptr && IP->right!=curr)
                    IP=IP->right;
                IP->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};