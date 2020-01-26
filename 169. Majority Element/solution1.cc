class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, maj = 0;
        
        for (auto i: nums) {
            if (cnt == 0) {
                maj = i;
                ++cnt;
            } else if (maj == i) ++cnt;
            else --cnt;
        }
        
        return maj;
    }
};
