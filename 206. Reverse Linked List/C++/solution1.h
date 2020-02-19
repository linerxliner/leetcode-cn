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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL, * curr = head, * succ = NULL;
        
        while (curr != NULL) {
            succ = curr->next;
            curr->next = new_head;
            new_head = curr;
            curr = succ;
        }
        
        return new_head;
    }
};
