// BFPRT(Constant coefficient of time complexity is too large to use this algorithm in normal situation.)
// Time: O(n), Space: O(n)

class Solution {
public:
    static const int kQ = 5;
    
    inline int TrivialSelect(vector<int>& nums, int begin, int end, int k) {
        sort(nums.begin() + begin, nums.begin() + end);
        
        return nums[k];
    }
    
    int KSelect(vector<int>& nums, int k) {
        if (nums.size() <= kQ) return TrivialSelect(nums, 0, nums.size(), k);
        
        vector<int> medians((nums.size() - 1) / kQ + 1), l, e, g;
        
        for (int i = 0; i * kQ < nums.size(); ++i)
            medians[i] = TrivialSelect(nums, i * kQ, (i + 1) * kQ < nums.size() ? (i + 1) * kQ : nums.size(), (nums.size() - 1) / 2);
        
        int m = KSelect(medians, (medians.size() - 1) / 2);
        
        for (auto i: nums) {
            if (i < m) l.push_back(i);
            else if (i > m) g.push_back(i);
            else e.push_back(i);
        }
        
        if (k < l.size()) return KSelect(l, k);
        else if (k < l.size() + e.size()) return m;
        else return KSelect(g, k - (l.size() + e.size()));
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return KSelect(nums, nums.size() - k);
    }
};
