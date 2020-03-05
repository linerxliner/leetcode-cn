/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, max_len = 0;
        unordered_set<int> window;
        
        for (int right = 0; right < s.size(); ++right) {
            while (window.count(s[right]) > 0) window.erase(s[left++]);
            window.insert(s[right]);
            max_len = max(max_len, int(window.size()));
        }
        
        return max_len;
    }
};
