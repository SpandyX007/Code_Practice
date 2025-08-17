/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    if(root==nullptr)
        return -1;
    Node* curr=root;
    int ceilval=-1;
    while(curr!=nullptr)
    {
        if(input==curr->data)
            return input;
        else if(input<curr->data)
        {
            if(curr->data>input)
                ceilval=curr->data;
            curr=curr->left;
        }
        else if(input>curr->data)
        {
            if(curr->data>input)
                ceilval=curr->data;
            curr=curr->right;
        }
    }
    return ceilval;
}