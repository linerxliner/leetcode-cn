// Mathematical method.
// Time: O(K * logN), Space: O(1)

class Solution {
public:
    int f(int T, int K, int N) {
        int c = 1, r = 0;
        
        for (int i = 1; i <= K; ++i) {
            c *= (T - i + 1);
            c /= i;
            r += c;
            
            if (r > N) return r;
        }
        
        return r;
    }
    
    int superEggDrop(int K, int N) {
        int lo = 1, hi = N + 1, mi;
        
        while (lo < hi) {
            mi = (lo + hi) >> 1;
            
            if (N <= f(mi, K, N)) hi = mi;
            else lo = mi + 1;
        }
        
        return lo;
    }
};
