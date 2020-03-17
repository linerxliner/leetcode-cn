/* Complexity
 *   Time: O(log(n))
 *   Space: O(1)
 * Description
 *   Binets method.
 */

class Solution {
public:
    vector<vector<long>> multiply(vector<vector<long>>& m1, vector<vector<long>>& m2) {
        vector<vector<long>> m3(2, vector<long>(2));

        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < 2; ++c) {
                m3[r][c] = m1[r][0] * m2[0][c] + m1[r][1] * m2[1][c];
            }
        }

        return m3;
    }

    int climbStairs(int n) {
        vector<vector<long>> answer = {{1, 0}, {0, 1}}, t = {{1, 1}, {1, 0}};

        while (n > 0) {
            if ((n & 1) == 1) answer = multiply(answer, t);
            t = multiply(t, t);
            n >>= 1;
        }

        return answer[0][0];
    }
};
