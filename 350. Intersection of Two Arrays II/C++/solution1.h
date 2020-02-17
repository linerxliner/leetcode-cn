// Counts elements in hashtable.
// Time: O(n + m), O(min(n + m))

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        vector<int> result;
        
        for (auto i: nums1.size() < nums2.size() ? nums1 : nums2) ++map1[i];
        
        for (auto i: nums1.size() < nums2.size() ? nums2 : nums1) {
            if (map1[i] > 0) {
                --map1[i];
                result.push_back(i);
            }
        }
        
        return result;
    }
};
