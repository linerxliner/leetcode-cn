/* Complexity
 *   Time: O(v)
 *   Space: O(v)
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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long max_width = 0;
        queue<pair<unsigned long long, TreeNode*>> q;

        q.push(make_pair(1, root));

        while (!q.empty()) {
            int size = q.size();

            max_width = max(max_width, q.back().first - q.front().first + 1);

            while (size--) {
                unsigned long long no = q.front().first;
                TreeNode* tn = q.front().second;

                q.pop();

                if (tn->left) q.push(make_pair(no * 2, tn->left));
                if (tn->right) q.push(make_pair(no * 2 + 1, tn->right));
            }
        }

        return max_width;
    }
};
