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
    bool isPalindrome(ListNode* head) {
        // find the middle of the LL (fast and slow pointers)
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        // middle point=slow

        // reverse the elements of the second half
        ListNode* curr=slow;
        ListNode* prev=nullptr;
        while(curr!=nullptr)
        {
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        // match the elements using two pointers method
        ListNode* left=head;
        ListNode* right=prev;
        while(right!=nullptr)
        {
            if(left->val!=right->val)
                return false;
            left=left->next;
            right=right->next;
        }
        return true;
    }
};
