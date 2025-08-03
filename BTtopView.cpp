/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// queue <Node,vertical>;
// map<vertical,int>

*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
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
            //create node if not present in map
            if(m.find(vertical)==m.end())
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