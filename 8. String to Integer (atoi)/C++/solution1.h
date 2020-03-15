/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    int myAtoi(string str) {
        int begin = 0;
        bool negtive = false;
        long num = 0;

        while (begin < str.size() && str[begin] == ' ') ++begin;

        if (begin >= str.size() || (str[begin] != '-' && str[begin] != '+' && !isdigit(str[begin]))) return 0;

        if (!isdigit(str[begin])) {
            if (str[begin] == '-') negtive = true;
            ++begin;
        }

        for (int i = begin; i < str.size() && isdigit(str[i]); ++i) {
            num *= 10;
            num += str[i] - '0';

            if (!negtive && num >= INT_MAX) return INT_MAX;
            else if (negtive && -num <= INT_MIN) return INT_MIN;
        }

        return negtive ? -num : num;
    }
};
