/* Complexity
 *   Time: O(n * m) ~ O(n + m)
 *   Space: O(m)
 * Description
 *   Sunday.
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = haystack.size(), m = needle.size();
        if (n < m) return -1;
        unordered_map<char, int> sunday;

        for (int j = 0; j < m; ++j) sunday[needle[j]] = m - j;

        for (int i =0; i + m <= n;) {
            if (haystack.substr(i, m) == needle) return i;
            else {
                if (i + m > n) break;
                if (sunday.count(haystack[i + m])) i += sunday[haystack[i + m]];
                else i += m + 1;
            }
        }

        return -1;
    }
};
