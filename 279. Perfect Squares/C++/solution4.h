// Lagrange's four-square theorem.
// Time: O(sqrt(n)), Space: O(1)

class Solution {
public:
    int numSquares(int n) {
        while ((n & 3) == 0) n >>= 2;
        if(int(sqrt(n)) * int(sqrt(n)) == n) return 1;
        if ((n & 7) == 7) return 4;
        for (int i = 1; i <= int(sqrt(n)); ++i) {
            int r = n - i * i;
            if (int(sqrt(r)) * int(sqrt(r)) == r) return 2;
        }
        return 3;
    }
};
