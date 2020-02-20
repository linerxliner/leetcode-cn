// DP. (It's actually an insertion sort, lol. I think about it by a complicated way, which is unnecessary and iconical.)
// Time: O(n^2), Space: O(n)

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int max_count = 0;
        vector<int> dp(nums.size() + 1), result(nums.size());

        dp[0] = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int cnt = max_count; cnt >= 0; --cnt) {
                if (nums[i] > dp[cnt]) {
                    result[i] = cnt;
                    dp[cnt + 1] = nums[i];
                    break;
                } else dp[cnt + 1] = dp[cnt];
            }
            ++max_count;
        }
        
        return result;
    }
};
