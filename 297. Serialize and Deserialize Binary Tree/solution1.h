/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string VectorToString(vector<TreeNode*>& v) {
        string result = "[";
        
        for (int i = 0; i < v.size(); ++i) {
            if (i != 0) result += ",";
            
            if (v[i]) result += to_string(v[i]->val);
            else result += "null";
        }
        
        return result + "]";
    }
    
    vector<int> StringToVector(string& s) {
        vector<int> result;
        char t[s.size() + 1], *p;
        
        strcpy(t, s.substr(1, s.size() - 2).c_str());
        
        p = strtok(t, ",");
        while (p) {
            if (strcmp(p, "null") == 0) result.push_back(INT_MAX);
            else result.push_back(atoi(p));
            p = strtok(NULL, ",");
        }
        
        return result;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        
        queue<TreeNode*> q;
        vector<TreeNode*> result;
        
        q.push(root);
        
        while (true) {
            bool has_non_null = false;
            int q_size = q.size();
            
            for (int i = 0; i < q_size; ++i) {
                TreeNode* curr = q.front(); q.pop();
                
                result.push_back(curr);
                
                if (curr) {
                    q.push(curr->left);
                    q.push(curr->right);
                    
                    if (curr->left) has_non_null = true;
                    else if (curr->right) has_non_null = true;
                }
            }
            
            if (!has_non_null) break;
        }
        
        return VectorToString(result);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v = StringToVector(data);
        queue<TreeNode*> q;
        TreeNode* root;
        
        if (v.size() == 0) return NULL;
        
        q.push(root = new TreeNode(v[0]));
        
        for (int i = 1; i < v.size(); i += 2) {
            TreeNode* curr = q.front(); q.pop();
            
            if (v[i] < INT_MAX) q.push(curr->left = new TreeNode(v[i]));
            if (v[i + 1] < INT_MAX) q.push(curr->right = new TreeNode(v[i + 1]));
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
