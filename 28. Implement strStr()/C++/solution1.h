/* Complexity
 *   Time: O(n * m)
 *   Space: O(1)
 * Description
 *   BF with i and j increasing at the same time when it is matching.
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int i = 0, j = 0;
        int n = haystack.size(), m = needle.size();

        while (i < n && j < m) {
            if (haystack[i] == needle[j]) {
                ++i; ++j;
            } else {
                i -= j - 1;
                j = 0;
            }
        }

        return j == m ? i - j : -1;
    }
};
