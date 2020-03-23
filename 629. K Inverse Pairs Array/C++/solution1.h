/* Complexity
 *   Time: O(n * k)
 *   Space: O(k)
 */

class Solution {
public:
    const int kMod = 1e9 + 7;

    int kInversePairs(int n, int k) {
        int total_ip_num = n * (n - 1) / 2;

        if (k > total_ip_num) return 0;
        else if (k > total_ip_num / 2) k = total_ip_num - k;

        vector<int> dp[2] = {vector<int>(k + 1, 0), vector<int>(k + 1, 0)};
        vector<int>* prev_dp = &dp[0], * curr_dp = &dp[1];

        (*prev_dp)[0] = (*curr_dp)[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                (*curr_dp)[j] = (*curr_dp)[j - 1];
                (*curr_dp)[j] = ((*curr_dp)[j] + (*prev_dp)[j]) % kMod;
                if (j >= i) (*curr_dp)[j] = ((*curr_dp)[j] + kMod - (*prev_dp)[j - i]) % kMod;
            }
            swap(prev_dp, curr_dp);
        }

        return (*prev_dp)[k];
    }
};
