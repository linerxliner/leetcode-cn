// Divide and conquer.
// Time: O(nlogn), Space: O(n)

class Solution {
public:
    vector<int> result, indexes;
        
    void Merge(vector<int> & nums, int begin, int mid, int end) {
        int l = begin, r = mid;
        vector<int> tmp(indexes.begin() + begin, indexes.begin() + mid);
        
        for (int i = 0; l < mid; ++i) {
            if (r >= end || nums[tmp[l - begin]] <= nums[indexes[r]]) {
                indexes[begin + i] = tmp[(l++) - begin];
                result[indexes[begin + i]] += r - mid;
            } else indexes[begin + i] = indexes[r++];
        }
    }
    
    void Count(vector<int> & nums, int begin, int end) {
        if (end - begin <= 1) return;
        
        int mid = (begin + end) >> 1;
        
        Count(nums, begin, mid);
        Count(nums, mid, end);
        
        Merge(nums, begin, mid, end);
    }

    vector<int> countSmaller(vector<int>& nums) {
        result = vector<int>(nums.size(), 0);
        indexes = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); ++i) indexes[i] = i;
        
        Count(nums, 0, nums.size());
        
        return result;
    }
};
