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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
        
        do {
            if (fast == NULL || fast->next == NULL) return NULL;
            else fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);
        
        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
