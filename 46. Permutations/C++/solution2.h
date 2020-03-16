/* Complexity
 *   Time: O(n!)
 *   Space: O(n!)
 * Description
 *   Swaps nums after beginning.
 */

class Solution {
public:
    vector<vector<int>> result;

    void GeneratePermutation(vector<int>& nums, int begin, int depth) {
        if (depth == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            GeneratePermutation(nums, begin + 1, depth + 1);
            swap(nums[begin], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        GeneratePermutation(nums, 0, 0);

        return result;
    }
};
