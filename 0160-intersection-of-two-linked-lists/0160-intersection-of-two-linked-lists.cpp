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
        //edge case : if any list is null we can't get intersection point
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }


        ListNode *a = headA;       //dummy node 1
        ListNode *b = headB;       //dummy node 2

        while(a!=b)
        {
            a = a ==NULL ? headB:a->next;   //Reasign the node to another list 
            b = b ==NULL ? headA:b->next;
        }

        return a;

        // ListNode *ptrA=headA,*ptrB=headB;
        
        // while(ptrA!=ptrB)
        // {
        //     if(ptrA==NULL)
        //     {
        //         ptrA=headB;
        //     }
        //     else{
        //         ptrA=ptrA->next;
        //     }
            
        //     if(ptrB==NULL)
        //     {
        //         ptrB=headA;
        //     }
        //     else{
        //         ptrB=ptrB->next;
        //     }
        // }
        // return ptrA;
        
    }
};