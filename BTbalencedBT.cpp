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
    int heightOfTree(TreeNode* root){
        if (root==nullptr)
            return 0;
        
        // if during recurrsion some eight lh or rh return a -1 value, then our funciton should return -1 immediately
        int lh=heightOfTree(root->left);
        if (lh==-1)
            return -1;
        int rh= heightOfTree(root->right);
        if (rh==-1)
            return -1;
        
        // checking for each node, if the abs diff of the two nodes are > 1, it would return -1; else return the height of the tree;
        if(abs(rh-lh)>1)
            return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        // we will be solving it by the help of height of a binary tree using recursion method
        int height=heightOfTree(root);
        return (height==-1) ? false:true;
    }
};