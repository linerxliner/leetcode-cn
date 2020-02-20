class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<long> s(nums.begin(), nums.end());
        int max_len = 0;
        
        for (auto i: s) {
            int len = 0;
            
            if (s.count(i - 1) == 0) {
                while (s.count(i++) > 0) ++len;
                max_len = max(max_len, len);
            }
        }
        
        return max_len;
    }
};
