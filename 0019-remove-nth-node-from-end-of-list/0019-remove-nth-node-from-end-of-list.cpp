class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        if(n == count){
            head=head->next;
            return head;
        }
        temp = head;
        for(int i=1;i<(count-n);i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};