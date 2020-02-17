class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        vector<int> result(nums.size());
        
        result[nums.size() - 1] = 1;
        for (int i = nums.size() - 2, succ = 1; i >= 0; --i) result[i] = succ *= nums[i + 1];
        for (int i = 0; i < nums.size(); ++i) {
            result[i] *= left;
            left *= nums[i];
        }
        
        return result;
    }
};
