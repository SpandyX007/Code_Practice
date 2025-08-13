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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return nullptr;
        
        map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        TreeNode* root= buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, m);

        return root;
    }

    TreeNode* buildTree(vector<int>& postorder,int postStart,int postEnd, vector<int>& inorder, int inStart, int inEnd,map<int,int>& m){
        if(inStart>inEnd || postStart>postEnd)
            return nullptr;
        
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inRoot=m[root->val];
        int numsLeft=inRoot-inStart;

        root->left=buildTree(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, m);

        root->right=buildTree(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, m);

        return root;
    }
};