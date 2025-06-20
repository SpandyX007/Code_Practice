/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr)
            return head;
        Node* curr=head;
        while(curr!=nullptr)
        {
            if(curr->child!=nullptr)
            {
                //recursively find the multilevel nodes
                Node* next=curr->next;
                curr->next=flatten(curr->child);
                curr->next->prev=curr;
                curr->child=nullptr;
                // find tail
                while(curr->next!=nullptr)
                    curr=curr->next;

                //connect the tail with the remaining nodes
                if(next!=nullptr)
                {
                    curr->next=next;
                    next->prev=curr;
                }
            }
            curr=curr->next;
        }
        return head;
    }
};