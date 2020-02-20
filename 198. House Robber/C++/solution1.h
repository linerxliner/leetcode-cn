class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        
        vector<int> dp(3);
        
        for (int i = 0; i < nums.size(); ++i) {
            int max_money = nums[i];
            
            if (i - 2 >= 0) max_money = max(max_money, dp[1] + nums[i]);
            if (i - 3 >= 0) max_money = max(max_money, dp[0] + nums[i]);
            
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max_money;
        }
        
        return max(dp[1], dp[2]);
    }
};
