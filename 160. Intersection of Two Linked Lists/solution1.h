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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode* curr_a = headA, * curr_b = headB;
        
        for (int i = 0; i< 2; ++i) {
            while (curr_a && curr_b) {
                curr_a = curr_a->next;
                curr_b = curr_b->next;
            }
            
            if (curr_a == NULL) curr_a = headB;
            else curr_b = headA;
        }
        
        while (curr_a != curr_b) {
            curr_a = curr_a->next;
            curr_b = curr_b->next;
        }
        
        return curr_a;
    }
};
