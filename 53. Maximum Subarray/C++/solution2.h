/* Complexity
 *   Time: O(n * log(n))
 *   Space: O(log(n))
 * Description
 *   Divide and conquer.
 */

class Solution {
public:
    int Divide(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return nums[lo];
        
        int mi = (lo + hi) / 2;
        int left_max = Divide(nums, lo, mi), right_max = Divide(nums, mi + 1, hi), center_max_l = INT_MIN, center_max_r = INT_MIN;
        
        for (int i = mi, t = 0; i >= lo; --i) {
            t += nums[i];
            center_max_l = max(center_max_l, t);
        }
        for (int i = mi + 1, t = 0; i <= hi; ++i) {
            t += nums[i];
            center_max_r = max(center_max_r, t);
        }
        
        return max(max(left_max, right_max), center_max_l + center_max_r);
    }
    
    int maxSubArray(vector<int>& nums) {
        return Divide(nums, 0, nums.size() - 1);
    }
};
