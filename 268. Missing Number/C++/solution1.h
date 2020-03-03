// Gauss summation formula.
// Time: O(n), Space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        
        for (auto n: nums) sum += n;
        
        return nums.size() * (nums.size() + 1) / 2 - sum;
    }
};
