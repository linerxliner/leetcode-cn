// DFS with pruning。
// Space: O(n)

class Solution {
public:
    int min_number = INT_MAX;
    
    void NumSquares(int r, int k, int d) {
        if (d >= min_number) return;
        
        if (r == 0) min_number = min(min_number, d);
        else if (r < 0) return;
        
        for (int i = k; i > 0; --i) NumSquares(r - i * i, i, d + 1);
    }
    
    int numSquares(int n) {
        NumSquares(n, int(sqrt(n)), 0);
        
        return min_number;
    }
};
