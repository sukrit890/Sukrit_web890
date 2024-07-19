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
    ListNode* deleteMiddle(ListNode* head) {
          if(head == nullptr || head->next==nullptr)
            return nullptr;

              ListNode* fast = head;
     ListNode* slow = head;
     ListNode* temp =slow;
    while(fast->next!=nullptr && fast->next->next!= nullptr )
    {
        temp = slow;
        fast= fast->next->next;
        slow = slow->next;
    }
    if(fast->next!=nullptr)
    {
        temp = slow;
        slow = slow->next;
    }
    temp->next=slow->next;
    return head;
    }
};