// Loop replacement.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        
        k = k % n;
        for (int begin = 0; cnt < n; ++begin) {
            int current = begin;
            int prev_num = nums[(current - k + n) % n];
            
            do {
                int tmp = nums[current];
                
                nums[current] = prev_num;
                prev_num = tmp;
                
                current = (current + k) % n;
                ++cnt;
            } while(current != begin);
        }
    }
};
