/* Complexity
 *   Time: O(v)
 *   Space: O(v)
 * Description
 *   Morris travelsal.
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
    vector<int> result;

    void TravelRightChain(TreeNode* x) {
        int size = result.size();

        while (x) {
            result.push_back(x->val);
            x = x->right;
        }
        reverse(result.begin() + size, result.end());
    }

    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* x = root;

        while (x) {
            if (x->left) {
                TreeNode* t = x->left;

                while (t->right && t->right != x) t = t->right;

                if (t->right) {
                    t->right = NULL;
                    TravelRightChain(x->left);
                    x = x->right;
                } else {
                    t->right = x;
                    x = x->left;
                }
            } else x = x->right;
        }
        TravelRightChain(root);

        return result;
    }
};
