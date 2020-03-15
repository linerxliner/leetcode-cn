/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int begin = 0, end = begin;

        for (int end = begin; end < nums.size(); ++begin, ++end) {
            nums[begin] = nums[end];
            while (end < nums.size() - 1 && nums[end] == nums[end + 1]) ++end;
        }

        return begin;
    }
};
