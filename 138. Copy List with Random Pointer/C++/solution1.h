/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* new_head = NULL;
        
        for (Node* curr = head,* new_curr; curr != NULL; curr = curr->next->next) {
            new_curr = new Node(curr->val);
            
            new_curr->next = curr->next;
            curr->next = new_curr;
        }
        
        for (Node* curr = head; curr != NULL; curr = curr->next->next) {
            if (curr->random != NULL) curr->next->random = curr->random->next;
        }
        
        for (Node* curr = head,* new_curr; curr != NULL; curr = curr->next) {
            new_curr = curr->next;
            if (new_head == NULL) new_head = new_curr;
            curr->next = curr->next->next;
            if (new_curr->next != NULL) new_curr->next = new_curr->next->next;
            else break;
        }
        
        return new_head;
    }
};
