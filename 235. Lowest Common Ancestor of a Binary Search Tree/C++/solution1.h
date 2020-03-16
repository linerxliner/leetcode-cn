/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* x = root;

        while (x) {
            if (p->val < x->val && q->val < x->val) x = x->left;
            else if (x->val < p->val && x->val < q->val) x = x->right;
            else return x;
        }

        return NULL;
    }
};
