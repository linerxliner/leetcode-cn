/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); ++i) {
            int n = target - nums[i];

            if (um.count(n) > 0) return {um[n], i};
            um[nums[i]] = i;
        }

        return {-1, -1};
    }
};
