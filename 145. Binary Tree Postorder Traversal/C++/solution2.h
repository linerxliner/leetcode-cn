/* Complexity
 *   Time: O(v)
 *   Space: O(h)
 * Description
 *   Double stack pushing.
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
        if (root == NULL) return {};

        TreeNode* x = root;
        stack<TreeNode*> s;
        vector<int> result;

        s.push(x); s.push(x);

        while (!s.empty()) {
            x = s.top(); s.pop();

            if (!s.empty() && x == s.top()) {
                if (x->right) {
                    s.push(x->right);
                    s.push(x->right);
                }
                if (x->left) {
                    s.push(x->left);
                    s.push(x->left);
                }
            } else result.push_back(x->val);
        }

        return result;
    }
};
