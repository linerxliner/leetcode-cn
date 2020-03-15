/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 * Description
 *   Manacher algorithm.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1, max_len_l = 0, center = 0, right = 0;
        string t = "#";
        vector<int> p(s.size() * 2 + 1, 0);

        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }

        for (int i = 0; i < t.size(); ++i) {
            if (i < right) p[i] = min(right - i, p[center - (right - center) + (right - i)]);

            int l = i - p[i] - 1, r = i + p[i] + 1;

            while (l >= 0 && r <= t.size() - 1 && t[l] == t[r]) {
                --l;
                ++r;
                ++p[i];
            }

            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }

            if (p[i] > max_len) {
                max_len = p[i];
                max_len_l = (i - p[i]) / 2;
            }
        }

        return s.substr(max_len_l, max_len);
    }
};
