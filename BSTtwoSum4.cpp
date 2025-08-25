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

// not at all optimised
// TC: O(n)   &&  SC:O(n)
class Solution {
public:
    void inordertrav(TreeNode* root,vector<int>& inorder){
        if(root!=nullptr)
        {
            inordertrav(root->left,inorder);
            inorder.push_back(root->val);
            inordertrav(root->right,inorder);
        }
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        unordered_map<int,int> m;
        inordertrav(root,inorder);
        //applying two sum using hashing
        for(int i=0;i<inorder.size();i++)
        {
            int first=inorder[i];
            int second=k-first;
            if(m.find(second)!=m.end())
                return true;
            m[first]=i;
        }
        return false;
    }
};

//Optimised (made by me)
// TC:O(n)      SC:O(H)*2
class BSTiterator{
private:
    stack<TreeNode*> s;
public:
    BSTiterator(TreeNode* root, bool reverse){
        reverse==false?pushAllLeft(root):pushAllRight(root);
    }
    // functions for BST iterator
    void pushAllLeft(TreeNode* node){
        while(node!=nullptr)
        {
            s.push(node);
            node=node->left;
        }
    }
    void pushAllRight(TreeNode* node){
        while(node!=nullptr)
        {
            s.push(node);
            node=node->right;
        }
    }
    int next(){
        TreeNode* top=s.top();
        s.pop();
        pushAllLeft(top->right);
        return top->val;
    }
    int before(){
        TreeNode* top=s.top();
        s.pop();
        pushAllRight(top->left);
        return top->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)
            return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);

        int i=l.next();
        int j=r.before();
        while(i<j)
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i=l.next();
            else
                j=r.before();
        }
        return false;
    }
};

// Same approach but best coding approach
// TC:O(n)      SC:O(H)*2
class BSTiterator{
private:
    stack<TreeNode*> s;
    bool reverse=true;
public:
    BSTiterator(TreeNode* root, bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    // functions for BST iterator
    void pushAll(TreeNode* node){
        while(node!=nullptr)
        {
            s.push(node);
            if(reverse==false)
                node=node->left;
            else
                node=node->right;
        }
    }
    int next(){
        TreeNode* top=s.top();
        s.pop();
        if(reverse==false)
            pushAll(top->right);
        else
            pushAll(top->left);
        return top->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)
            return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i=l.next();
            else
                j=r.next();
        }
        return false;
    }
};