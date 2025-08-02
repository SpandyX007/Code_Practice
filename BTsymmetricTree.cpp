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
    bool isSymmetric(TreeNode* root) {
        return (root==nullptr) || isSymmetricHelping(root->left, root->right);
    }
    bool isSymmetricHelping(TreeNode* leftnode, TreeNode* rightnode){
        if(leftnode==nullptr || rightnode==nullptr)
            return leftnode==rightnode;
        if(leftnode->val!=rightnode->val)
            return false;
        return (isSymmetricHelping(leftnode->left, rightnode->right) && isSymmetricHelping(leftnode->right, rightnode->left));
    }
};