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

// queue<Node,level>;
// map<level,Node->val>
// the value of the node in the map should be updated

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        queue<pair<TreeNode*,int>> q;
        map<int,int> m;

        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int level=it.second;

            //create or update node if not present in map
            m[level]=node->val;
            if(node->left!=nullptr)
                q.push({node->left,level+1});
            if(node->right!=nullptr)
                q.push({node->right,level+1});
        }
        // inserting the map in the vector and returning
        for(auto ele:m)
            ans.push_back(ele.second);
        return ans;
    }
};