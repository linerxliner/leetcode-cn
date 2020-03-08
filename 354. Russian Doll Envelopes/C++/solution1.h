/* Complexity
 *   Time: O(n * log(n))
 *   Space: O(n)
 */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp;
        
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& e1, const vector<int>& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        
        for (auto e: envelopes) {
            int i = lower_bound(dp.begin(), dp.end(), e[1]) - dp.begin();
            
            if (i == dp.size()) dp.push_back(e[1]);
            else if (e[1] < dp[i]) dp[i] = e[1];
        }
        
        return dp.size();
    }
};
