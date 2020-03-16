/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    int reverse(int x) {
        long y = 0;

        for (; x != 0; x /= 10) {
            y *= 10;
            y += x % 10;
            if (y < INT_MIN || y > INT_MAX) return 0;
        }

        return y;
    }
};
