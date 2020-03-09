/* Complexity
 *   Time: O(log(n))
 *   Space: O(1)
 * Description
 *   Newton's method.
 */

class Solution {
public:
    int mySqrt(int x) {
        double r = 1, p = 0;
        
        while (abs(r - p) >= 1e-2) {
            p = r;
            r -= (r * r - x) / (2 * r);
        }
        
        return int(r);
    }
};
