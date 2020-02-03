// Dynamic programming.
// Time: O(n), Space: O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return vector<int>();

        vector<int> right(nums.size()), left(nums.size()), max_nums(nums.size() - k + 1);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i % k == 0) right[i] = nums[i];
            else right[i] = max(right[i - 1], nums[i]);
            
            if ((nums.size() - i) % k == 0 || i == 0) left[nums.size() - i - 1] = nums[nums.size() - i - 1];
            else left[nums.size() - i - 1] = max(left[nums.size() - i], nums[nums.size() - i - 1]);
        }
        
        for (int i = 0; i <= nums.size() - k; ++i) max_nums[i] = max(left[i], right[i + k - 1]);
        
        return max_nums;
    }
};
