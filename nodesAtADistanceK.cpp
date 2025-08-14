/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                m[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                m[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Hashing all the nodes to it's parents
        unordered_map<TreeNode*, TreeNode*> m;
        findParents(root,m,target);

        // Applying BFS from the target node and calculating the distance simultaneously
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int distance=0;
        while(!q.empty())
        {
            int size=q.size();
            if(distance++ == k)
                break;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                // left side
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                // right side
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                // top side(parent)
                if(m[curr] && !visited[m[curr]])
                {
                    q.push(m[curr]);
                    visited[m[curr]]=true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
        }

        return ans;

    }
};