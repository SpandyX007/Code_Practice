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

// TC: O(n)     SC:O(H)
class Solution {
public:
    void invertConnections(TreeNode* node){
        if(node!=nullptr)
        {
            TreeNode* nodeLeft=node->left;
            node->left=node->right;
            node->right=nodeLeft;
            invertConnections(node->left);
            invertConnections(node->right);
        }
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return root;
        invertConnections(root);
        return root;
    }
};