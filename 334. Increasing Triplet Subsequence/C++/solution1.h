class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int idx1 = -1, idx2 = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (idx1 == -1 || nums[i] < nums[idx1]) idx1 = i;
            else if (idx1 != -1 && nums[idx1] < nums[i] && (idx2 == -1 || nums[i] < nums[idx2])) idx2 = i;
            else if (idx2 != -1 && nums[idx2] < nums[i]) return true;
        }
        
        return false;
    }
};
