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
    ListNode* reverseList(ListNode* head) {
      ListNode* ptr=head;
      ListNode* prev=nullptr;
      ListNode* front=nullptr;
      while(ptr!=nullptr){
        front=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=front;
      }
      return prev;
    }
};