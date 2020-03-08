/* Complexity
 *   Time: O(n * log(k))
 *   Space: O(k)
 * Description
 *   Min heap to get min ListNode from k Lists.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL, * curr = head;
        auto cmp = [](ListNode* ln1, ListNode* ln2) { return ln1->val > ln2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (auto ln: lists) {
            if (ln != NULL) pq.push(ln);
        }
        
        while (!pq.empty()) {
            ListNode* succ = pq.top(); pq.pop();
            
            if (head == NULL) head = curr = succ;
            else {
                curr->next = succ;
                curr = curr->next;
            }
            
            if (succ->next) pq.push(succ->next);
        }
        
        return head;
    }
};
