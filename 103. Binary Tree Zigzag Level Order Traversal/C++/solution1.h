/* Complexity
 *   Time: O(n)
 *   Space: O(n)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        bool l_to_r = true;
        deque<TreeNode*> s;
        vector<vector<int>> result;
        
        s.push_back(root);
        
        while (!s.empty()) {
            int s_size = s.size();
            vector<int> layer;
            
            while (s_size--) {
                if (l_to_r) {
                    TreeNode* curr = s.front(); s.pop_front();
                    
                    layer.push_back(curr->val);
                    if (curr->left) s.push_back(curr->left);
                    if (curr->right) s.push_back(curr->right);
                } else {
                    TreeNode* curr = s.back(); s.pop_back();
                    
                    layer.push_back(curr->val);
                    if (curr->right) s.push_front(curr->right);
                    if (curr->left) s.push_front(curr->left);
                }
            }
            
            result.push_back(layer);
            l_to_r = !l_to_r;
        }
        
        return result;
    }
};
