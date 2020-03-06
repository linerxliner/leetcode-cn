/* Complexity
 *   Time: O(log(n))
 *   Space: O(1)
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mi;
        
        if (nums.empty()) return -1;
        
        while (lo < hi) {
            mi = (lo + hi) >> 1;
            if (nums[lo] < nums[mi]) {
                if (nums[lo] <= target && target <= nums[mi]) hi = mi;
                else lo = mi;
            } else if (nums[lo] > nums[mi]) {
                if (nums[mi] <= target && target <= nums[hi]) lo = mi;
                else hi = mi;
            } else {
                if (nums[lo] == target) return lo;
                else if (nums[hi] == target) return hi;
                else return -1;
            }
        }
        
        return nums[0] == target ? 0 : -1;
    }
};


