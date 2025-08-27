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

// there can be two main cases in this problem:
// 1. Two adjacent elements needs to be swapped i.e swap(first,middle)
// 2. Two elements(not adjacent) needs to be swapped i.e swap(first,last)

// TC: O(n)   &   SC:stack_space

// using morrisInorder SC:O(1)
class Solution {
private:
    TreeNode* first;
    TreeNode* prev; // this is used for traversal purpose
    TreeNode* last;
    TreeNode* middle;
public:
    void checkPointers(TreeNode* root){
        if(prev!=nullptr && (prev->val>root->val))
            {
                //if first violation, mark this two nodes as
                //'first' and 'middle'
                if(first==nullptr)
                {
                    first=prev;
                    middle=root;
                }
                //if second violation, mark this node as last
                else
                    last=root;
            }
            prev=root;
    }
    void morrisInorder(TreeNode* root){
        // using Moris inorder traversal for optimising space
        TreeNode* curr=root;
        while(curr!=nullptr)
        {
            if(curr->left==nullptr)
            {
                checkPointers(curr);
                curr=curr->right;
            }
            else
            {
                TreeNode* IP=curr->left;
                while(IP->right!=nullptr && IP->right!=curr)
                    IP=IP->right;
                if(IP->right==nullptr)
                {
                    IP->right=curr;
                    curr=curr->left;
                }
                else
                {
                    IP->right=nullptr;
                    checkPointers(curr);
                    curr=curr->right;
                }
            }
        }
    }
    void recoverTree(TreeNode* root) {
        first=middle=last=nullptr;
        prev=new TreeNode(INT_MIN);
        morrisInorder(root);
        if(first && last)
            swap(first->val,last->val);
        else if(first && middle)
            swap(first->val,middle->val);
    }
};


// runtime of this is 0ms where as using morris runtime is 2ms(dunno why?)
class Solution {
private:
    TreeNode* first;
    TreeNode* prev; // this is used for traversal purpose
    TreeNode* last;
    TreeNode* middle;
public:
    void inorder(TreeNode* root){
        if(root!=nullptr)
        {
            inorder(root->left);
            if(prev!=nullptr && (prev->val>root->val))
            {
                //if first violation, mark this two nodes as
                //'first' and 'middle'
                if(first==nullptr)
                {
                    first=prev;
                    middle=root;
                }
                //if second violation, mark this node as last
                else
                    last=root;
            }
            prev=root;
            inorder(root->right);
        }
        return;
    }
    void recoverTree(TreeNode* root) {
        first=middle=last=nullptr;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
            swap(first->val,last->val);
        else if(first && middle)
            swap(first->val,middle->val);
    }
};