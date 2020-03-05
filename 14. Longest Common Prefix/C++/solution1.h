/* Complexity
 *   Time: O(n * min(string_len))
 *   Space: O(1)
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char c;
        
        if (strs.empty()) return "";
        else if (strs.size() == 1) return strs[0];
        
        for (int j = 0; ; ++j) {
            for (int i = 0; i < strs.size(); ++i) {
                if (j == strs[i].size()) return strs[0].substr(0, j);
                if (i > 0 && strs[i][j] != strs[i - 1][j]) return strs[0].substr(0, j);
            }
        }
    }
};
