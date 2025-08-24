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

// not at all optimised
// TC: O(n)   &&  SC:O(n)
class Solution {
public:
    void inordertrav(TreeNode* root,vector<int>& inorder){
        if(root!=nullptr)
        {
            inordertrav(root->left,inorder);
            inorder.push_back(root->val);
            inordertrav(root->right,inorder);
        }
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        unordered_map<int,int> m;
        inordertrav(root,inorder);
        //applying two sum using hashing
        for(int i=0;i<inorder.size();i++)
        {
            int first=inorder[i];
            int second=k-first;
            if(m.find(second)!=m.end())
                return true;
            m[first]=i;
        }
        return false;
    }
};