/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";

        string s="";
        queue<TreeNode*> q;
        q.push(root);
        s+=to_string(root->val)+",";
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            // appending the node's value after converting into string
            if(curr->left)
            {
                s+=to_string(curr->left->val)+",";
                q.push(curr->left);
            }
            // if nullptr is found, append "#"
            else
                s+="#,";
            if(curr->right)
            {
                s+=to_string(curr->right->val)+",";
                q.push(curr->right);
            }
            else
                s+="#,";
        }

        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return nullptr;

        stringstream s(data);  // string is converted to objects
        string str;
        getline(s,str,','); // iterates linearly over the stream where the delimiter is the ','
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            getline(s,str,','); // iterates to the next char
            if(str=="#")
                curr->left=nullptr;
            else
            {
                TreeNode* leftNode=new TreeNode(stoi(str));
                curr->left=leftNode;
                q.push(leftNode);
            }

            getline(s,str,','); // iterates to the next char
            if(str=="#")
                curr->right=nullptr;
            else
            {
                TreeNode* rightNode=new TreeNode(stoi(str));
                curr->right=rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));