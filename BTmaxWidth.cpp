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

// this can be achieved by level order traversing and using heap(segmatation tree) concepts
// queue<Node,Index> q;
// maxWidth=LastWidth-FirstWidth+1;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root==nullptr)
            return 0;
        int maxWidth=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});   // 0-indexed
        while(!q.empty())
        {
            int size=q.size();
            int mmin=q.front().second;  //to make the id starting from zero
            int LastWidth,FirstWidth;
            for(int i=0;i<size;i++)
            {
                int curr_id=q.front().second-mmin;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)    //if i is the first ele
                    FirstWidth=curr_id;
                if(i==size-1)   //if i is the last ele
                    LastWidth=curr_id;
                if(node->left)
                    q.push({node->left,(long long)curr_id*2+1});
                if(node->right)
                    q.push({node->right,(long long)curr_id*2+2});
            }
            maxWidth=max(maxWidth,LastWidth-FirstWidth+1);
        }
        return maxWidth;
    }
};