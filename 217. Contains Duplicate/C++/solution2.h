// Tests duplicate by hash table.
// Time: O(n), Space: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique_nums;
        
        for (auto i: nums) {
            if (unique_nums.count(i) > 0) return true;
            unique_nums.insert(i);
        }
        
        return false;
    }
};
