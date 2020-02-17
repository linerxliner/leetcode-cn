class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0];
        int prev_min_product = nums[0], prev_max_product = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int min_tmp = prev_min_product, max_tmp = prev_max_product;
            
            prev_min_product = min(nums[i], min(min_tmp * nums[i], max_tmp * nums[i]));
            prev_max_product = max(nums[i], max(min_tmp * nums[i], max_tmp * nums[i]));
            
            max_product = max(prev_max_product, max_product);
        }
        
        return max_product;
    }
};
