/* Complexity
 *   Time: O(max(m, n))
 *   Time: O(max(m, n))
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_l = new ListNode(0), * curr = new_l, * new_l1 = l1, * new_l2 = l2;
        
        while (new_l1 != NULL || new_l2 != NULL) {
            int v1 = 0, v2 = 0, v3;
            
            if (new_l1) {
                v1 = new_l1->val;
                new_l1 = new_l1->next;
            }
            if (new_l2) {
                v2 = new_l2->val;
                new_l2 = new_l2->next;
            }
            
            v3 = v1 + v2 + curr->val;
            curr->val = v3 % 10;
            if (!(v3 / 10 == 0 && new_l1 == NULL && new_l2 == NULL)) curr->next = new ListNode(v3 / 10);
            
            curr = curr->next;
        }
        
        return new_l;
    }
};
