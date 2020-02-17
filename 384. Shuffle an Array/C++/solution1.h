class Solution {
public:
    vector<int> original_nums;
    vector<int> current_nums;
    default_random_engine e;
    
    Solution(vector<int>& nums) {
        original_nums = nums;
        current_nums = nums;
        e.seed(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = current_nums.size() - 1; i > 0; --i) swap(current_nums[i], current_nums[e() % (i + 1)]);
        
        return current_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
