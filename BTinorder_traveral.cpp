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

// TC: O(n)     SC:O(n)
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        inorder(root, result);
        return result;
    }
private:
    void inorder(TreeNode* node, vector<int>& result)
    {
        if(node==nullptr) return;
        inorder(node->left,result);
        result.push_back(node->val);
        inorder(node->right,result);
    }
};

// Morris Inorder Traversal     TC:O(n)     SC:O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                // finding IP
                TreeNode* IP=curr->left;
                while(IP->right!=nullptr && IP->right!=curr)
                    IP=IP->right;
                
                if(IP->right==nullptr)
                {
                    IP->right=curr; //creating the connection
                    curr=curr->left;
                }
                else
                {
                    IP->right=nullptr;//deleting the connection
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};