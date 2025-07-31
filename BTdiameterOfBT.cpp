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

 // Brute-force approach, where we calculate the height of every node(left side and right side), and add the distance 
 // TC: O(n^2)
class Solution {
public:
    int heightDiff(TreeNode* root){
        // this returns the height of given root till the leaf node
        if(root==nullptr)
            return 0;
        int lh=heightDiff(root->left);
        int rh=heightDiff(root->right);
        
        return 1+max(rh,lh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDist=0;
        int findlh=heightDiff(root->left);
        int findrh=heightDiff(root->right);
        int diffOfLhRh=abs(findlh+findrh);
        maxDist=max(maxDist,diffOfLhRh);
        // return maxDist;
        return maxDist;
    }
};

// Optimised Code
// TC: O(n)

class Solution {
public:
    int ans=0;
    int Treeheight(TreeNode* root){
        // this returns the height of given root till the leaf node
        if(root==nullptr)
            return 0;
        int lh=Treeheight(root->left);
        int rh=Treeheight(root->right);
        
        ans=max(ans,lh+rh);
        return 1+max(rh,lh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        Treeheight(root);
        return ans;
    }
};