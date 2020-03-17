/* Complexity
 *   Time: O(m)
 *   Space: O(1)
 * Description
 *   Combination.
 */

class Solution {
public:
    long Combination(int m, int n) {
        long result = 1;

        if (m > n - m) m = n - m;

        for (int i = n - m + 1; i <= n; ++i) result *= i;
        for (int i = 2; i <= m; ++i) result /= i;

        return result;
    }

    int uniquePaths(int m, int n) {
        return Combination(m - 1, m + n - 2);
    }
};
