/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)   // no nodes
            return head;
        if(head->next==nullptr) // only one node
            return head;
        
        //declaring variables
        ListNode* prev=nullptr;
        ListNode* first=head;
        ListNode* second=head->next;
        while(first!=nullptr && second!=nullptr)
        {
            ListNode* nodenext=second->next;
            //swaping the nodes
            second->next=first;
            first->next=nodenext;

            if(prev!=nullptr)
                prev->next=second;
            else
                head=second;
            //necessary updations for next iterations
            prev=first;
            first=nodenext;
            if(nodenext!=nullptr)
                second=nodenext->next;
            else
                second=nullptr;
        }
        return head;
    }
};