/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;

        long y = 0, t = x;

        for (; t != 0; t /= 10) {
            y *= 10;
            y += t % 10;
        }

        return x == y;
    }
};
