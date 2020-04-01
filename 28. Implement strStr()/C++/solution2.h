/* Complexity
 *   Time: O(n * m)
 *   Space: O(1)
 * Description
 *   BF with only j increasing when it is matching.
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = haystack.size(), m = needle.size();

        for (int i = 0; i < n - m + 1; ++i) {
            int j;
            for (j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == m) return i;
        }

        return -1;
    }
};
