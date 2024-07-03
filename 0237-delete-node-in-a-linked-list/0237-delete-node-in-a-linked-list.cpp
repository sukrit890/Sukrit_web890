class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        while(temp) {
            if(temp->next != nullptr) {
                swap(temp->val, temp->next->val);
            }
            temp = temp->next;
        }
        ListNode* prev;
        while(node->next) {
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
    }
};