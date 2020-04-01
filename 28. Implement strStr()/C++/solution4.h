/* Complexity
 *   Time: O(n + m) ~ O(n / m)
 *   Space: O(m)
 * Description
 *   BM(BC + GS).
 */

class Solution {
public:
    void BuildBC(string& needle, int m, unordered_map<char, int>& bc) {
        for (int i = 0; i < m; ++i) bc[needle[i]] = i;
    }

    void BuildSS(string& needle, int m, vector<int>& ss) {
        ss[m - 1] = m;

        for (int lo = m - 1, hi = m - 1, j = lo - 1; j >= 0; --j) {
            if (lo < j && ss[m - hi +j - 1] <= j - lo) ss[j] = ss[m - hi +j - 1];
            else {
                hi = j;
                lo = min(lo, hi);
                while (0 <= lo && needle[lo] == needle[m - hi + lo - 1]) --lo;
                ss[j] = hi - lo;
            }
        }
    }

    void BuildGS(string& needle, int m, vector<int>& gs) {
        vector<int> ss(m);

        BuildSS(needle, m, ss);

        for (int i = 0, j = m - 1; j >= 0; --j) {
            if (j + 1 == ss[j]) {
                while (i < m - j - 1) gs[i++] = m - j - 1;
            }
        }

        for (int j = 0; j < m - 1; ++j) gs[m -ss[j] - 1] = m - j - 1;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int i = 0;
        int n = haystack.size(), m = needle.size();
        unordered_map<char, int> bc;
        vector<int> gs(m, m);

        BuildBC(needle, m, bc);
        BuildGS(needle, m, gs);

        while (i + m <= n) {
            int j = m - 1;

            while (haystack[i + j] == needle[j]) {
                if (--j < 0) break;
            }

            if (j < 0) return i;
            else {
                i += max(gs[j], bc.count(haystack[i + j]) ? j - bc[haystack[i + j]] : j + 1);
            }
        }

        return -1;
    }
};
