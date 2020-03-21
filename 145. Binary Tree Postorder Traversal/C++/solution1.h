/* Complexity
 *   Time: O(v)
 *   Space: O(h)
 * Description
 *   Goes to heightest left visible form left.
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
    void GotoHLVFL(stack<TreeNode*>& s) {
        while (TreeNode* x = s.top()) {
            if (x->left) {
                if (x->right) s.push(x->right);
                s.push(x->left);
            } else s.push(x->right);
        }
        s.pop();
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return {};

        TreeNode* x = root;
        stack<TreeNode*> s;
        vector<int> result;

        s.push(x);

        while (!s.empty()) {
            if (s.top()->left != x && s.top()->right != x) GotoHLVFL(s);
            x = s.top(); s.pop();
            result.push_back(x->val);
        }

        return result;
    }
};
