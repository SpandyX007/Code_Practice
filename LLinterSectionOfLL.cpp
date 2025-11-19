/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // brute force- using hashmap
        unordered_map<ListNode*,int> m;
        ListNode* currA=headA;        
        while(currA)
        {
            if(m.find(currA)==m.end())
                m[currA]=1;
            else
                m[currA]++;
            currA=currA->next;
        }
        ListNode* currB=headB;
        while(currB)
        {
            if(m.find(currB)!=m.end())
                return currB;
            currB=currB->next;
        }
        return nullptr;
    }
};


// 2nd Approach
class Solution {
public:
    ListNode *collisionPoint(ListNode *headA, ListNode *headB,int diff)
    {
        ListNode* tempA=headA;
        ListNode* tempB=headB;

        for(int i=0;i<diff;i++)
            tempA=tempA->next;
        // compare the nodes side by side
        while(tempA)
        {
            if(tempA==tempB)
                return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA=headA;
        ListNode* currB=headB;
        int countA=0;
        int countB=0;
        while(currA)
        {
            currA=currA->next;
            countA++;
        }
        while(currB)
        {
            currB=currB->next;
            countB++;
        }
        int diffA=countA-countB;
        int diffB=countB-countA;
        
        //shifting the longer by the difference
        if(diffA>diffB)
            return collisionPoint(headA,headB,diffA);
        else
            return collisionPoint(headB,headA,diffB);
    }
};




// 3rd Approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // make two pointers.say currA and currB, for headA and headB and iterate it over the LL. If one of the currA comes to the end assign currA to headB and iterate again. Same for currB

        if(headA==nullptr || headB==nullptr)
            return nullptr;

        ListNode* currA=headA;
        ListNode* currB=headB;

        while(currA!=currB)
        {
            currA=currA->next;
            currB=currB->next;
            if(currA==currB)
                return currA;
            if(currA==nullptr)
                currA=headB;
            if(currB==nullptr)
                currB=headA;
        }

        return currA;
    }
};
