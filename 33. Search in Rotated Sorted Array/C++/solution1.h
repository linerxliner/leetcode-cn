/* Complexity
 *   Time: O(log(n))
 *   Space: O(1)
 * Description
 *   Binary search by getting situation of interval from nums[0]. 
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(), mi;
        
        while (lo < hi) {
            mi = (lo + hi) >> 1;
            if ((nums[0] <= target) ^ (target <= nums[mi]) ^ (nums[0] > nums[mi])) lo = mi + 1;
            else hi = mi;
        }
        
        return 0 <= lo && lo < nums.size() && nums[lo] == target ? lo : -1;
    }
};


