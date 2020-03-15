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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;

        int len = 0;
        ListNode* left = head, * right = head, * new_head;

        for (ListNode* curr = head; curr != NULL; curr = curr->next) ++len;
        if ((k %= len) == 0) return head;

        while (k--) right = right->next;
        for (; right->next != NULL; left = left->next, right = right->next);
        new_head = left->next;
        right->next = head;
        left->next = NULL;

        return new_head;
    }
};
