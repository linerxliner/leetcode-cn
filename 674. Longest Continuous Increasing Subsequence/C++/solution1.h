/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int lcis = 0;
        
        for (int begin = 0, end = 1; end < nums.size(); ++end) {
            while (end < nums.size() && nums[end - 1] < nums[end]) ++end;
            lcis = max(lcis, end - begin);
            begin = end;
        }
        
        return lcis;
    }
};
