/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(1)
 * Description
 *   Central expansion method.
 */

class Solution {
public:
    int DetectPalindromeFromCenter(string s, int l, int r) {
        int len = (r - l == 1 ? 0 : 1);

        while (l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
            --l;
            ++r;
            len += 2;
        }

        return len;
    }

    string longestPalindrome(string s) {
        int max_len = 1, max_len_l = 0;

        for (int c = 0; c < s.size(); ++c) {
            int odd_len = DetectPalindromeFromCenter(s, c - 1, c + 1);
            int even_len = DetectPalindromeFromCenter(s, c, c + 1);

            if (max(odd_len, even_len) > max_len) {
                max_len = max(odd_len, even_len);
                if (odd_len > even_len) max_len_l = c - odd_len / 2;
                else max_len_l = c - even_len / 2 + 1;
            }
        }

        return s.substr(max_len_l, max_len);
    }
};
