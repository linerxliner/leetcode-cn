/* Complexity
 *   Time: O(log(n))
 *   Space: O(1)
 * Description
 *   Fibonacci formula.
 */

class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);

        return (1 / sqrt5) * (pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1));
    }
};
