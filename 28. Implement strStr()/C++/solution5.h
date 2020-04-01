/* Complexity
 *   Time: O(n + m)
 *   Space: O(1)
 */

class Solution {
public:
    const int kR = 128;
    const int kM = 4096;

    int GenDM(int m) {
        int dm = 1, prod = 1;

        while (m) {
            if (m & 1) dm = (dm * prod) % kM;
            m >>= 1;
            prod = (prod * kR) % kM;
        }

        return dm;
    }

    int GenFP(string& s, int begin, int end) {
        int fp = 0;

        for (int i = begin; i < end; ++i) fp = (fp * kR + s[i]) % kM;

        return fp;
    }

    int UpdateFP(int fp, string& s, int begin, int end, int dm) {
        fp = (fp - dm * s[begin]) % kM;
        fp = (fp * kR + s[end]) % kM;

        return fp < 0 ? fp + kM : fp;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = haystack.size(), m = needle.size();
        if (n < m) return -1;
        int i = 0;
        int haystack_fp = GenFP(haystack, 0, m), needle_fp = GenFP(needle, 0, m);
        int dm = GenDM(m);

        while (true) {
            if (haystack_fp == needle_fp && haystack.substr(i, m) == needle) return i;
            if (++i > n - m) break;
            haystack_fp = UpdateFP(haystack_fp, haystack, i - 1, i + m - 1, dm);
        }

        return -1;
    }
};
