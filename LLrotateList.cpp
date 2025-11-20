// MyCode: brute force ig
// running fine in lesser values of k.
// Error: TLE

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
            return head;

        for(int i=0;i<k;i++)
        {
            ListNode* curr=head;
            ListNode* prev=head;
            // transfering curr till the last
            while(curr->next)
            {
                prev=curr;
                curr=curr->next;
            }
            curr->next=head;
            prev->next=nullptr;
            head=curr;
        }
        return head;
    }
};

// reduced computation by decreasing the k by k%n
// TC:O(n^2)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
            return head;
        
        ListNode* temp=head;
        int len=0;
        while(temp)
        {
            temp=temp->next;
            len++;
        }
        if(k%len==0)
            return head;
        else
        {
            for(int i=0;i<k%len;i++)
            {
                ListNode* curr=head;
                ListNode* prev=head;
                // transfering curr till the last
                while(curr->next)
                {
                    prev=curr;
                    curr=curr->next;
                }
                curr->next=head;
                prev->next=nullptr;
                head=curr;
            }
        }
        return head;
    }
};

// Optimised code
// TC: O(n)
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
    ListNode* findNewLastNode(ListNode* head,int k){
        int count=1;
        ListNode* curr=head;
        while(curr)
        {
            if(count==k)
                return curr;
            count++;
            curr=curr->next;
        }
        return curr;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
            return head;
        
        ListNode* tail=head;
        int len=1;
        while(tail->next)
        {
            tail=tail->next;
            len++;
        }
        if(k%len==0)
            return head;
        k=k%len;

        // attach the tail to the head
        tail->next=head;
        ListNode* newLastNode=findNewLastNode(head,len-k);
        head=newLastNode->next;
        newLastNode->next=nullptr;

        return head;
    }
};