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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_head = NULL, *odd_tail = NULL, * even_head = NULL, * even_tail = NULL;
        
        for (bool is_odd = true; head != NULL; head = head->next, is_odd = !is_odd) {
            if (is_odd) {
                if (odd_head == NULL) odd_head = odd_tail = head;
                else {
                    odd_tail->next = head;
                    odd_tail = odd_tail->next;
                }
            } else {
                if (even_head == NULL) even_head = even_tail = head;
                else {
                    even_tail->next = head;
                    even_tail = even_tail->next;
                }
            }
        }
        
        if (odd_tail != NULL) odd_tail->next = even_head;
        if (even_tail != NULL) even_tail->next = NULL;
        
        return odd_head;
    }
};
