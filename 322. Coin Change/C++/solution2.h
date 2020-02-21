// DFS.
// Space: O(n)

class Solution {
public:
    int min_depth = INT_MAX;
    
    void DFS(vector<int>& coins, int amount, int begin, int depth) {
        if (amount == 0) {
            min_depth = min(min_depth, depth);
            return;
        } else if (amount < 0) return;
        
        if (amount % coins[begin] == 0) {
            min_depth = min(min_depth, depth + amount / coins[begin]);
            return;
        }
        
        if (depth + (amount - 1) / coins[begin] + 1 >= min_depth) return;
        
        for (int i = begin; i < coins.size(); ++i) DFS(coins, amount - coins[i], i, depth + 1);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        DFS(coins, amount, 0, 0);
        
        return min_depth == INT_MAX ? -1 : min_depth;
    }
};
