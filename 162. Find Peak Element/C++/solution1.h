class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, mi = 0;
        
        while (lo < hi) {
            mi = (lo + hi) >> 1;
            
            if (nums[mi] > nums[mi + 1]) hi = mi;
            else lo = mi + 1;
        }
        
        return lo;
    }
};
