/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /* iterative method
typedef struct ListNode* LIST;

LIST createnode(){
    LIST temp=(LIST)malloc(sizeof(struct ListNode));
    temp->next=NULL;
    return temp;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    LIST dummy=createnode();
    LIST curr=dummy;
    if(list1==NULL && list2==NULL)  return list1;
    if(list1!=NULL && list2==NULL)  return list1;
    if(list1==NULL && list2!=NULL)  return list2;
    while(list1!=NULL && list2!=NULL)
    {
        if (list1->val <= list2->val)
        {
            curr->val=list1->val;
            list1=list1->next;
        }
        else
        {
            curr->val=list2->val;
            list2=list2->next;
        }
        if (list1==NULL || list2==NULL)
            break;
        LIST temp=createnode();
        curr->next=temp;
        curr=curr->next;
    }
    
    curr->next = (list1 != NULL) ? list1 : list2;

    return dummy;
}
*/

// recursive method

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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1==nullptr || head2==nullptr)
            return head1==nullptr? head2 : head1;
        
        if(head1->val <=head2->val)
        {
            head1->next=mergeTwoLists(head1->next,head2);
            return head1;
        }
        if(head1->val >=head2->val)
        {
            head2->next=mergeTwoLists(head1,head2->next);
            return head2;
        }
        return head1;
    }
};