/* Complexity
 *   Time: O(n * log(k))
 *   Space: O(k)
 * Description
 *   Merge sort.
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
        if (lists.empty()) return NULL;
        
        ListNode* head = NULL, * curr = head;
        queue<ListNode*> q;
        int q_size;
        
        for (auto ln: lists) q.push(ln);
        
        while ((q_size = q.size()) > 1) {
            while (q_size) {
                ListNode* ln1, * ln2, * new_ln = NULL, * curr_ln = new_ln;
                
                ln1 = q.front(); q.pop(); --q_size;
                if (q_size) {
                    ln2 = q.front(); q.pop(); --q_size;
                } else {
                    q.push(ln1);
                    break;
                }
                
                while (ln1 != NULL && ln2 != NULL) {
                    if (ln1->val <= ln2->val) {
                        if (new_ln == NULL) new_ln = curr_ln = ln1;
                        else {
                            curr_ln->next = ln1;
                            curr_ln = curr_ln->next;
                        }
                        ln1 = ln1->next;
                    } else {
                        if (new_ln == NULL) new_ln = curr_ln = ln2;
                        else {
                            curr_ln->next = ln2;
                            curr_ln = curr_ln->next;
                        }
                        ln2 = ln2->next;
                    }
                }
                
                if (ln1) (new_ln ? curr_ln->next : new_ln) = ln1;
                else if (ln2) (new_ln ? curr_ln->next : new_ln) = ln2;
                
                if (new_ln) q.push(new_ln);
            }
        }
        
        return q.empty() ? NULL : q.front();
    }
};
