/* Complexity
 *   Time: O(n)
 *   Space: O(1)
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        
        ListNode* l = NULL, * curr = NULL;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                if (l == NULL) l = curr = l1;
                else {
                    curr->next = l1;
                    curr = curr->next;
                }
                l1 = l1->next;
            } else {
                if (l == NULL) l = curr = l2;
                else {
                    curr->next = l2;
                    curr = curr->next;
                }
                l2 = l2->next;
            }
        }
        
        if (l1 != NULL) curr->next = l1;
        else curr->next = l2;
        
        return l;
    }
};
