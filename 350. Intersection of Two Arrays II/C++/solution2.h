// Compares two arrays after sorting.
// Time: O(nlogn + mlogm), Space: O(1)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int j = 0;
        vector<int> result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for (int i = 0; i < nums1.size(); ++i) {
            while (j < nums2.size() && nums1[i] > nums2[j]) ++j;
            if (j < nums2.size() && nums1[i] == nums2[j]) result.push_back(nums2[j++]);
        }
        
        return result;
    }
};
