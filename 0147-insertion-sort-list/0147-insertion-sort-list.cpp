class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = head, *nextNode = head->next;
        newHead->next = nullptr;
        ListNode* temp, *temp1, *temp2;
        while (nextNode != nullptr){
            if (newHead->val > nextNode->val){
                temp = nextNode->next;
                nextNode->next = newHead;
                newHead = nextNode;
                nextNode = temp;
                continue;
            }
            temp = newHead;
            while (temp->next != nullptr && temp->next->val < nextNode->val) temp = temp->next;
            temp1 = temp->next;
            temp->next = nextNode;
            temp2 = nextNode->next;
            nextNode->next = temp1;
            nextNode = temp2;
        }
        return newHead;
    }
};