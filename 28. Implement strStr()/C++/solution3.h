/* Complexity
 *   Time: O(n + m)
 *   Space: O(m)
 * Description
 *   KMP.
 */

class Solution {
public:
    void BuildNext(string& needle, vector<int>& next, int m) {
        int j = 0, t = -1;

        while (j < m - 1) {
            if (t < 0 || needle[j] == needle[t]) {
                ++j; ++t;
                next[j] = (needle[j] != needle[t]) ? t : next[t];
            } else t = next[t];
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int i = 0, j = 0;
        int n = haystack.size(), m = needle.size();
        vector<int> next(m, -1);

        BuildNext(needle, next, m);

        while (i < n && j < m) {
            if (j < 0 || haystack[i] == needle[j]) {
                ++i; ++j;
            } else j = next[j];
        }

        return j == m ? i - j : -1;
    }
};
