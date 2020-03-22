/* Complexity
 *   Time: O(n * log(sum(A)))
 *   Space: O(1)
 * Description
 *   Binary search.
 */

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long lo = INT_MIN, hi = 0;

        for (auto n: nums) {
            lo = max(lo, long(n));
            hi += n;
        }

        while (lo < hi) {
            long mi = (lo + hi) / 2;
            long interval_sum = 0;
            int interval_num = 1;

            for (auto n: nums) {
                interval_sum += n;

                if (interval_sum > mi) {
                    ++interval_num;
                    interval_sum = n;
                }
            }

            if (interval_num > m) lo = mi + 1;
            else hi = mi;
        }

        return lo;
    }
};
