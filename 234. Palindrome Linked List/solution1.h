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
    ListNode* ReverseList(ListNode* head) {
        ListNode* new_head = NULL;
        
        while (head != NULL) {
            ListNode* succ = head->next;
            head->next = new_head;
            new_head = head;
            head = succ;
        }
        
        return new_head;
    }
    
    ListNode* FirstHalfTail(ListNode* head) {
        ListNode* slow = head, * fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        bool is_palindrome = true;
        ListNode* second_half_head = ReverseList(FirstHalfTail(head)->next);
        
        for (ListNode* curr1 = head, * curr2 = second_half_head; curr1 != NULL && curr2 != NULL; curr1 = curr1->next, curr2 = curr2->next) {
            if (curr1->val != curr2->val) {
                is_palindrome = false;
                break;
            }
        }
        ReverseList(second_half_head);
        
        return is_palindrome;
    }
};
