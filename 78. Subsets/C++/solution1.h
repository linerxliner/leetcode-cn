/* Complexity
 *   Time: O(n * (2 ^ n))
 *   Space: O(2 ^ n)
 * Description
 *   Incremental construction.
 */

class Solution {
public:
    vector<vector<int>> result;

    void GenerateSubsets(vector<int>& nums, int last_used_idx, vector<int>& answer, int answer_len) {
        result.push_back(vector<int>(answer.begin(), answer.begin() + answer_len));

        for (int i = last_used_idx + 1; i < nums.size(); ++i) {
            answer[answer_len] = nums[i];
            GenerateSubsets(nums, i, answer, answer_len + 1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> answer(nums.size());

        GenerateSubsets(nums, -1, answer, 0);

        return result;
    }
};
