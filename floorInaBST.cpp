// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        int ans=-1;
        Node* curr=root;
        while(curr!=nullptr)
        {
            if(curr->data==x)
            {
                ans=x;
                break;
            }
            else if(x<curr->data)
                curr=curr->left;
            else if(x>curr->data)
            {
                if(ans<=curr->data)
                    ans=curr->data;
                curr=curr->right;
            }
        }
        return ans;
    }
};