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

// queue<pair<node,pair<vertical,level>>> q;
// map<vertical,map<level,multiset<node_no>>> m;
// mapping vertical with level and node
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> m;

        // level order traversal according to the queue
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int vertical=p.second.first;     //vertical
            int level=p.second.second;    //level
            m[vertical][level].insert(node->val);
            if(node->left)
                q.push({node->left,{vertical-1,level+1}});
            if(node->right)
                q.push({node->right,{vertical+1,level+1}});
        }
        vector<vector<int>> ans;
        for(auto p:m)
        {
            vector<int>col;
            for(auto q:p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());    //inserting all values of multiset from beginning into the vector in descending order 
            ans.push_back(col);
        }
        return ans;
    }
};