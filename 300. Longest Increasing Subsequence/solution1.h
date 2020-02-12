// DP.
// Time: O(nlogn), Space: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        dp.push_back(INT_MIN);
        for (auto n: nums) {
            if (n > dp[dp.size() - 1]) dp.push_back(n);
            else *lower_bound(dp.begin(), dp.end(), n) = n;
        }
        
        return dp.size() - 1;
    }
};
