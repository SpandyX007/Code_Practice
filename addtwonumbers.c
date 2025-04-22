struct ListNode l1{
    int val;
    struct ListNode *next;
};
struct ListNode l2{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode* LIST;
    LIST curr1=l1;
    LIST curr2=l2;

    //fetching the number from LL1
    int n1=0;
    int count1=0;
    while(curr1->next!=NULL)
    {
        n1=n1+curr1->val*pow(10,count1);
        count1++;
    }

    //fetching the number from LL1
    int n2=0;
    int count2=0;
    while(curr1->next!=NULL)
    {
        n2=n2+curr1->val*pow(10,count2);
        count2++;
    }

    int result=n1+n2;

    LIST dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val=0;
    dummyHead->next=NULL;
    LIST curr=dummyHead;
    while(result!=0)
    {
        int pop=result%10;
        curr->val=pop;
        curr->next=malloc(sizeof(struct ListNode));
        curr=curr->next;
        result=result/10;
    }
    LIST result1 = dummyHead;
    free(dummyHead);
    return result1;
}