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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr || l2==nullptr)
            return nullptr;
        // if(l1->next==nullptr && l2->next==nullptr)
        //     return new ListNode(l1->val+l2->val);

        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        int carry=0;

        while(l1 || l2 || carry)
        {
            int sum=carry;
            if(l1)
                sum+=l1->val;
            if(l2)
                sum+=l2->val;
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            curr->next=newNode;
            curr=curr->next;

            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }

        if(carry)
            ListNode* newNode=new ListNode(carry);

        return dummy->next;
    }
};