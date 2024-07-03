class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 != nullptr || temp2 != nullptr){
            int sum  = carry;

            if(temp1 != nullptr){
                sum = sum + temp1 -> val;
            }

            if(temp2 != nullptr){
                sum = sum + temp2 -> val;
            }

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr -> next = newNode;
            curr = curr -> next;

            if(temp1 != nullptr){
                temp1 = temp1 -> next;
            }

            if(temp2 != nullptr){
                temp2 = temp2 -> next;
            }
        }

        if(carry != 0){
            ListNode* kk = new ListNode(carry);
            curr -> next = kk;
        }

        return dummy -> next;

    }
};