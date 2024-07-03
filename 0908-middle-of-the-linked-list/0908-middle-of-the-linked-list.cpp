class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //Tortoise-Hare Method
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL){// don't write (fast->next!=NULL && fast!=NULL)
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;// Let's Upvote
    }
};