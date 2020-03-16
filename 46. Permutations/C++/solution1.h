/* Complexity
 *   Time: O(n ^ n)
 *   Space: O(n!)
 * Description
 *   Adds unused element into prev permutations.
 */

class Solution {
public:
    vector<vector<int>> result;

    void GeneratePermutation(vector<int>& nums, vector<int>& answer, set<int>& used, int depth) {
        if (depth == nums.size()) {
            result.push_back(answer);
            return;
        }

        for (auto n: nums) {
            if (used.count(n) == 0) {
                used.insert(n);
                answer[depth] = n;
                GeneratePermutation(nums, answer, used, depth + 1);
                used.erase(n);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> answer(nums.size());
        set<int> used;

        GeneratePermutation(nums, answer, used, 0);

        return result;
    }
};
