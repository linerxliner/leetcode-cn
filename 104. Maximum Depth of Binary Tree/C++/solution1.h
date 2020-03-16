/* Complexity
 *   Time: O(v)
 *   Space: O(h)
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
    int maxDepth(TreeNode* root) {
        int max_depth = 0, depth = 1;
        TreeNode* x = root;
        stack<pair<TreeNode*, int>> s;

        while (true) {
            while (x) {
                max_depth = max(max_depth, depth++);
                if (x->right) s.push(make_pair(x->right, depth));
                x = x->left;
            }
            if (s.empty()) break;
            x = s.top().first;
            depth = s.top().second;
            s.pop();
        }

        return max_depth;
    }
};
