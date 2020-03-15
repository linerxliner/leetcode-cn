/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    string reverseWords(string s) {
        for (int begin = 0, end = begin; end <= s.size(); ++end) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + begin, s.begin() + end);
                begin = end + 1;
            }
        }

        return s;
    }
};
