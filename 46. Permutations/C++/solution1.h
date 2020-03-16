/* Complexity
 *   Time: O(n ^ n)
 *   Space: O(n!)
 * Description
 *   Adds unused element into prev permutations.
 */

class Solution {
public:
    vector<vector<int>> result;

    void GeneratePermutation(vector<int>& nums, vector<int>& answer, int depth) {
        if (depth == nums.size()) {
            result.push_back(answer);
            return;
        }

        for (auto n: nums) {
            if (find(answer.begin(), answer.begin() + depth, n) == (answer.begin() + depth)) {
                answer[depth] = n;
                GeneratePermutation(nums, answer, depth + 1);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> answer(nums.size());

        GeneratePermutation(nums, answer, 0);

        return result;
    }
};
