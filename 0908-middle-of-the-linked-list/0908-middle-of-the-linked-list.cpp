class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = countNode(head);
        if(n%2==0){
            int p = n/2 +1;
            for(int i=1;i<p && head;i++){
               head = head -> next;
            }
            return head;
        }
        else{
            int m = (n+1)/2;
            for(int i =1; i<m;i++){
                head = head -> next;
            }
            return head;
        }
    }
    
    int countNode(ListNode* head){
        int count =0;
        while(head != NULL){
            count++;
            head = head -> next;
        }
        return count;
    }
};