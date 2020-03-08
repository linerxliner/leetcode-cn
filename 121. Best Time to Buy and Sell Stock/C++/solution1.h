/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int min_price = prices[0], max_profit = 0;
        
        for (int p: prices) {
            min_price = min(min_price, p);
            max_profit = max(max_profit, p - min_price);
        }
        
        return max_profit;
    }
};
