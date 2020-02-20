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
    int max_path_sum = INT_MIN;
    
    int Traverse(TreeNode *root) {
        if (!root) return 0;
        
        int left_max = max(Traverse(root->left), 0), right_max = max(Traverse(root->right), 0);
        
        max_path_sum = max(max_path_sum, root->val + left_max + right_max);
        
        return root->val + max(left_max, right_max);
    }
    
    int maxPathSum(TreeNode* root) {
        Traverse(root);
        
        return max_path_sum;
    }
};
