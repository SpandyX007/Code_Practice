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
    int ans=INT_MIN;
    int heightOfTree(TreeNode* node){
        if (node==nullptr)
            return 0;
        
        // standing on a node, we calculate the leftsum and the rightsum of the node store it to the ans. The ans is compared to every back-tracking step and the ultimate maximum ans is stored.
        int lsum=max(0,heightOfTree(node->left));
        int rsum=max(0,heightOfTree(node->right));

        // back-tracking step
        ans=max(ans,lsum+rsum+node->val);

        // this step is for identifying the path we came across
        return node->val+max(lsum,rsum);
    }

    int maxPathSum(TreeNode* root) {
        heightOfTree(root);
        return ans;
    }
};