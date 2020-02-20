class Solution {
public:
    int len;
    
    inline int ActualIdx(int idx) {
        return (1 + 2 * idx) % (len | 1);
    }
    
    void wiggleSort(vector<int>& nums) {
        int median;
        int lo = 0, hi = nums.size() - 1, idx = lo;
        
        len = hi + 1;
        nth_element(nums.begin(), nums.begin() + len / 2, nums.end());
        median = *(nums.begin() + len / 2);
        
        while (idx <= hi) {
            if (nums[ActualIdx(idx)] > median) swap(nums[ActualIdx(lo++)], nums[ActualIdx(idx++)]);
            else if (nums[ActualIdx(idx)] < median) swap(nums[ActualIdx(idx)], nums[ActualIdx(hi--)]);
            else ++idx;
        }
    }
};
