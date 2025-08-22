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

// using upperbound to check the element is on the left or right
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& i, int bound){
        if(i==preorder.size() || preorder[i]>bound)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        TreeNode* root=build(preorder,i,INT_MAX);
        return root;
    }
};