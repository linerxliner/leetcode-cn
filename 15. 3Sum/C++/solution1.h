/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(n)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l, r, t;
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 3 || nums[0] > 0 && nums[nums.size() - 1] > 0 || nums[0] < 0 && nums[nums.size() - 1] < 0) return result;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) break;
            
            l = i + 1, r = nums.size() - 1;
            
            while (l < r) {
                t = nums[i] + nums[l] + nums[r];
                if (t == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r - 1] == nums[r]) --r;
                    ++l; --r;
                } else if (t < 0) ++l;
                else --r;
            }
            
            while (i < nums.size() - 3 && nums[i] == nums[i + 1]) ++i;
        }
        
        return result;
    }
};
