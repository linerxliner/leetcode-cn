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
    ListNode* sortList(ListNode* head) {
        int overall_len = 0;
        
        for (ListNode *curr = head; curr != NULL; curr = curr->next, ++overall_len);
        
        for (int interval = 1; interval < overall_len; interval <<= 1) {
            ListNode* new_head = NULL, * prev = new_head;
            
            for (int round = 0; round < (overall_len + interval - 1) / (2 * interval); ++round) {
                ListNode* left = (prev == NULL ? head : prev->next), * right = left;
                int left_len = interval, right_len = (round + 1) * 2 * interval > overall_len ? overall_len - (round * 2 * interval + interval): interval;
                
                for (int i = 0; i < left_len; ++i) right = right->next;
                
                while (left_len > 0 && right_len > 0) {
                    if (left->val <= right->val) {
                        if (new_head == NULL) new_head = prev = left;
                        else {
                            prev->next = left;
                            prev = prev->next;
                        }
                        left = left->next;
                        --left_len;
                    } else {
                        if (new_head == NULL) new_head = prev = right;
                        else {
                            prev->next = right;
                            prev = prev->next;
                        }
                        right = right->next;
                        --right_len;
                    }
                }
                
                if (left_len > 0) {
                    prev->next = left;
                    while (left_len--) prev = prev->next;
                    prev->next = right;
                } else {
                    prev->next = right;
                    while (right_len--) prev = prev->next;
                }
            }
            
            head = new_head;
        }
        
        return head;
    }
};
