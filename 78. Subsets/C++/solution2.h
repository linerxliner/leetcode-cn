/* Complexity
 *   Time: O(2 ^ n)
 *   Space: O(2 ^ n)
 * Description
 *   Bitmap construction.
 */

class Solution {
public:
    vector<vector<int>> result;

    void GenerateSubsets(vector<int>& nums, vector<bool>& bits, int depth) {
        if (depth == nums.size()) {
            vector<int> answer;

            for (int i = 0; i < bits.size(); ++i) {
                if (bits[i]) answer.push_back(nums[i]);
            }
            result.push_back(answer);

            return;
        }

        GenerateSubsets(nums, bits, depth + 1);
        bits[depth] = true;
        GenerateSubsets(nums, bits, depth + 1);
        bits[depth] = false;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> bits(nums.size(), false);

        GenerateSubsets(nums, bits, 0);

        return result;
    }
};
