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

// the code is same as BFS, but with added 'flag' concept
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        //flag helps to maintain the zigzag pattern
        bool flag=true;

        while(!q.empty())
        {
            int size=q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                //find position to fill node's value
                int index=flag ? i : (size-i-1);

                row[index]=node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            //everything is done for the level
            flag=!flag;     //changing the value of flag
            ans.push_back(row);
        }
        return ans;
    }
};