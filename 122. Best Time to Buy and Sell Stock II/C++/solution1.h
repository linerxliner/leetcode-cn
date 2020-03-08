/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); ++i) max_profit += max(0, prices[i] - prices[i - 1]);
        
        return max_profit;
    }
};
