/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 * Description
 *   DP.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0, max_sum = INT_MIN;
        
        for (int n: nums) {
            prev = max(0, prev) + n;
            max_sum = max(max_sum, prev);
        }
        
        return max_sum;
    }
};
