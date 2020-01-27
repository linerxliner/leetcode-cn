// Dynamic programming with binary search.
// Time: O(K * N * logN), Space: O(K * N)
class Solution {
public:
    static const int kMaxK = 100 + 5;
    static const int kMaxN = 10000 + 5;
    
    int dp[kMaxK][kMaxN];
    
    int DP(int k, int n) {
        if (dp[k][n] >= 0) return dp[k][n];
        else if (k == 1) return n;
        else if (n == 0) return 0;
        else {
            int lo = 1, hi = n + 1, mi;
            int t1, t2;
            
            while (lo < hi) {
                mi = (lo + hi) >> 1;
                
                t1 = DP(k - 1, mi - 1);
                t2 = DP(k, n - mi);
                
                if (t1 < t2) lo = mi + 1;
                else hi = mi;
            }
            
            t1 = max(DP(k - 1, lo - 1), DP(k, n - lo));
            if (lo > 1) t2 = max(DP(k - 1, lo - 2), DP(k, n - lo + 1));
            
            return dp[k][n] = 1 + (lo > 1 ? min(t1, t2) : t1);
        }
    }
    
    int superEggDrop(int K, int N) {
        memset(dp, -1, sizeof(dp));
        return DP(K, N);
    }
};
