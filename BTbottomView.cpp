/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

// queue<Node,vertical>;
// map<vertical,Node->val>

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        queue<pair<Node*,int>> q;
        map<int,int> m;
        
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int vertical=it.second;
            //create or update node if not present in map
            m[vertical]=node->data;
            if(node->left!=nullptr)
                q.push({node->left,vertical-1});
            if(node->right!=nullptr)
                q.push({node->right,vertical+1});
        }
        // inserting the map in the vector and returning
        for(auto ele:m)
            ans.push_back(ele.second);
        return ans;
    }
};