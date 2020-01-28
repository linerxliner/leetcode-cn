// Dynamic programming with optimal strategy.
// Time: O(K * N), Space: O(N)

class Solution {
public:
    static const int kMaxN = 10000 + 5;
    
    int dp0[kMaxN], dp1[kMaxN];
    
    int superEggDrop(int K, int N) {
        int * prev_dp = dp0, * curr_dp = dp1, * t_dp;
        
        for (int n = 0; n <= N; ++n) prev_dp[n] = n;
        
        for (int k = 2; k <= K; ++k) {
            int x = 1;
            
            curr_dp[0] = 0; curr_dp[1] = 1;
            for (int n = 2; n <= N; ++n) {
                while (max(prev_dp[x - 1], curr_dp[n - x]) > max(prev_dp[x], curr_dp[n - x - 1])) ++x;
                
                curr_dp[n] = max(prev_dp[x - 1], curr_dp[n - x]) + 1;
            }
            
            t_dp = curr_dp;
            curr_dp = prev_dp;
            prev_dp = t_dp;
        }
        
        return prev_dp[N];
    }
};
