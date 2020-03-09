/* Complexity
 *   Time: O(log(n))
 *   Space: O(1)
 * Description
 *   Binary search.
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        long lo = 1, hi = x / 2, mi;
        
        while (lo < hi) {
            mi = (lo + hi + 1) >> 1;
            
            if (mi * mi > x) hi = mi - 1;
            else lo = mi;
        }
        
        return lo;
    }
};
