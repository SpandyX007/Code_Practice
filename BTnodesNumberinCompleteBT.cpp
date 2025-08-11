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
    int nodes=0;
    int countNodes(TreeNode* root) {
        // brute force using  inorder traversal: counting all the nodes using traversal
        // TC: O(n)   SC: O(n)
        if(root!=nullptr)
        {
            countNodes(root->left);
            nodes++;
            countNodes(root->right);
        }
        return nodes;
    }
};


// Optimised Code   TC: O(logn)^2  SC:O(logn)

// in a complete the binary tree the number of nodes
// nodes = 2^(height of tree) - 1
//total height of tree = 1 + (left subtree) + (right subtree)

class Solution {
public:
    int calcLeftHeight(TreeNode* node)
    {
        int leftheight=0;
        while(node)
        {
            leftheight++;
            node=node->left;
        }
        return leftheight;
    }

    int calcRightHeight(TreeNode* node)
    {
        int rightheight=0;
        while(node)
        {
            rightheight++;
            node=node->right;
        }
        return rightheight;
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int lh=calcLeftHeight(root);
        int rh=calcRightHeight(root);

        if(lh==rh)
            return (1<<lh) - 1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};