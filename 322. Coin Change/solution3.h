// IDA*.
// Space: O(n)

class Solution {
public:
    bool IDA(vector<int>& coins, int amount, int begin, int depth, int max_depth) {
        if (amount == 0) return true;
        else if (amount < 0) return false;
        
        if (amount % coins[begin] == 0 && depth + amount / coins[begin] <= max_depth) return true;
        
        if (depth + (amount - 1) / coins[begin] + 1 > max_depth || depth >= max_depth) return false;
        
        for (int i = begin; i < coins.size(); ++i) {
            if (IDA(coins, amount - coins[i], i, depth + 1, max_depth)) return true;
        }
        
        return false;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        for (int max_depth = 0; max_depth <= amount / coins[coins.size() - 1]; ++max_depth) {
            if (IDA(coins, amount, 0, 0, max_depth)) return max_depth;
        }
        
        return -1;
    }
};
