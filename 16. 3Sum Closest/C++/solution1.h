/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(1)
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (abs(target - sum) < abs(target - ans)) ans = sum;

                if (sum < target) ++l;
                else if (sum > target) --r;
                else return ans;
            }
        }

        return ans;
    }
};
