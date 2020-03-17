/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 * DP.
 */

class Solution {
public:
    int climbStairs(int n) {
        int f = 0, g = 1;

        while (n--) {
            g += f;
            f = g - f;
        }

        return g;
    }
};
