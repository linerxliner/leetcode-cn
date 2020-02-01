// Quick select.
// Time: AVG O(n), MAX O(n^2), Space: O(1)

class Solution {
public:
    default_random_engine e;
    
    int findKthLargest(vector<int>& nums, int k) {
        e.seed(time(0));
        
        --k;
        for (int lo = 0, hi = nums.size() - 1; lo < hi;) {
            swap(nums[lo], nums[lo + e() % (hi - lo + 1)]);
            
            int i = lo, j = hi, pivot = nums[i];
            
            while (i < j) {
                while ((i < j) && (nums[j] <= pivot)) --j; nums[i] = nums[j];
                while ((i < j) && (pivot <= nums[i])) ++i; nums[j] = nums[i];
            }
            nums[i] = pivot;
            
            if (i < k) lo = i + 1;
            else if (k < i) hi = i - 1;
            else break;
        }
        
        return nums[k];
    }
};
