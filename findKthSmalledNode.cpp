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

//The inorder traversal of a BST is always sorted
// After traversing we will return the kth smallest value

// TC: O(n)     SC:O(n)

class Solution {
public:
    int counter=1;
    TreeNode* node;
    void inorder(TreeNode* root,int k){
        if(root!=nullptr)
        {
            inorder(root->left,k);
            if(counter++==k)
                node= root;
            cout<<root->val<<"\t";
            inorder(root->right,k);
        }
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);

        return node->val;
    }
};


// Using morris traversal
// TC: O(n)     SC:O(1)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter=1;
        TreeNode* node;
        TreeNode* curr=root;
        while(curr!=nullptr)
        {
            if(curr->left==nullptr)
            {
                // cout<<curr->val<<"\t";
                if(counter++==k)
                    node=curr;
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
                    if(counter++==k)
                        node=curr;
                    // cout<<curr->val<<"\t";
                    curr=curr->right;
                }
            }
        }
        return node->val;
        // return -1;
    }
};