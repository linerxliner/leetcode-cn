/* Complexity
 *   Time: O(v)
 *   Space: O(v)
 * Description
 *   Transfers VRL (right-first preorder traversal) to LRV.
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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* x = root;
        vector<int> result;
        stack<TreeNode*> s;

        while (true) {
            while (x) {
                result.push_back(x->val);
                if (x->left) s.push(x->left);
                x = x->right;
            }
            if (s.empty()) break;
            x = s.top(); s.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
