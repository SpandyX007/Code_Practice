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

    bool isLeaf(TreeNode* node){
        return (!node->left && !node->right);
    }

    void dfs(TreeNode* root, stack<TreeNode*>& s,string& ans, vector<string>& result){
        s.push(root);
        int len = ans.length();  // Save current length for backtracking
        ans+=to_string(s.top()->val)+"->";
        if(isLeaf(root))
        {
            result.push_back(ans.substr(0,ans.length()-2));
            s.pop();  // Backtrack the stack
            ans.resize(len);  // Backtrack the string
            return;
        }
        if(root->left!=nullptr)
            dfs(root->left,s,ans,result);
        if(root->right!=nullptr)
            dfs(root->right,s,ans,result);
        s.pop();  // Backtrack the stack when not leaf
        ans.resize(len);  // Backtrack the string when not leaf
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string ans="";
        if(root==nullptr)
            return result;
        stack<TreeNode*> s;
        dfs(root,s,ans,result);
        return result;
    }
};