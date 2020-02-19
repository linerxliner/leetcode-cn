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
    enum TreeNodeState {kBoth, kRight, kNone};
    
    stack<pair<TreeNode*, TreeNodeState>> s;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = NULL;
        bool one_found = false;
        
        s.push(make_pair(root, kBoth));
        
        while (!s.empty()) {
            if (s.top().second == kNone) {
                if (one_found && lca == s.top().first) {
                    s.pop();
                    lca = s.top().first;
                } else s.pop();
            } else {
                TreeNode* next = NULL;
                
                if (s.top().second == kBoth) {
                    if (s.top().first == p || s.top().first == q) {
                        if (one_found) return lca;
                        else {
                            one_found = true;
                            lca = s.top().first;
                        }
                    }
                    if (s.top().first->left) next = s.top().first->left;
                } else {
                    if (s.top().first->right) next = s.top().first->right;
                }
                
                s.top().second = TreeNodeState(s.top().second + 1);
                if (next) s.push(make_pair(next, kBoth));
            }
        }
        
        return lca;
    }
};
