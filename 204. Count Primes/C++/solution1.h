/* Complexity
 * Time: O(n * log(n))
 * Space: O(n)
 */

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;
        
        int cnt = 0;
        vector<bool> primes(n, true);
        
        primes[0] = primes[1] = false;
        for (int base = 2; base * base < n; ++base) {
            if (primes[base]) {
                for (int num = base * base; num < n; num += base) primes[num] = false;
            }
        }
        
        for (int base = 2; base < n; ++base) {
            if (primes[base]) ++cnt;
        }
        
        return cnt;
    }
};
