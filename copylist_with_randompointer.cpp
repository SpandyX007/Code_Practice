//TC : O(2n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //unordered map for storing the random values
        unordered_map<Node*,Node*> m;
        Node* curr=head;
        Node* newhead;
        
        //simply traversing and deep copying the orginal list
        if(head==nullptr)
            return head;

        if(head->next==nullptr)
            newhead=new Node(head->val);

        newhead=new Node(head->val);
        m[head]=newhead;
        curr=curr->next;
        Node* newcurr=newhead;
        while(curr!=nullptr)
        {
            Node* temp=new Node(curr->val);
            m[curr]=temp;
            newcurr->next=temp;
            newcurr=newcurr->next;
            curr=curr->next;
        }

        //traversing again to assign the random values
        curr=head;
        newcurr=newhead;
        while(curr!=nullptr)
        {
            newcurr->random=m[curr->random];
            newcurr=newcurr->next;
            curr=curr->next;
        }

        return newhead;
    }
};