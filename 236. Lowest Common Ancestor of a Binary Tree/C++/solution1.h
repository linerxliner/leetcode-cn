// Finds LCA indicated by two subtrees using recursion.
// Time: O(n), Space: O(n)

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
    TreeNode* ca = NULL;
    
    bool Search(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool curr_flag = false, left_flag = false, right_flag = false;
        
        if (root == p) curr_flag = true;
        else if (root == q) curr_flag = true;
        
        if (root->left) left_flag = Search(root->left, p, q);
        if (root->right) right_flag = Search(root->right, p, q);
        
        if (curr_flag + left_flag + right_flag >= 2 && ca == NULL) ca = root;
        
        return curr_flag | left_flag | right_flag;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Search(root, p, q);
        
        return ca;
    }
};
