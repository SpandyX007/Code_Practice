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
    ListNode* oddEvenList(ListNode* head) {
        // brute force solution
        vector<int> arr;
        ListNode* curr=head;
        ListNode* evenNode=head->next;
        while(curr && curr->next!=nullptr)
        {
            arr.push_back(curr->val);
            curr=curr->next->next;
        }
        if(curr)
            arr.push_back(curr->val);

        while(evenNode!=nullptr && evenNode->next!=nullptr)
        {
            arr.push_back(evenNode->val);
            evenNode=evenNode->next->next;
        }
        if(evenNode)
            arr.push_back(evenNode->val);

        ListNode* temp=head;
        int i=0;
        while(temp)
        {
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }

        return head;
    }
};


// optimised
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        
        ListNode* currOdd=head;
        ListNode* currEven=head->next;
        ListNode* evenNode=head->next;

        while(currEven && currEven->next)
        {
            currOdd->next=currOdd->next->next;
            currEven->next=currEven->next->next;
            currOdd=currOdd->next;
            currEven=currEven->next;
        }
        currOdd->next=evenNode;

        return head;
    }
};