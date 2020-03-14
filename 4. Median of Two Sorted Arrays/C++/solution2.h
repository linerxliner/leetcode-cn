/* Complexity
 *   Time: O(min(m, n))
 *   Space: O(1)
 * Description
 *   Divides from the middles of two lists and balances two sides.
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int len1 = nums1.size(), len2 = nums2.size(), lo = 0, hi = len1;

        if (len1 == 0) return len2 % 2 ? nums2[len2 / 2] : (nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2.0;

        while (lo <= hi) {
            int idx1 = (lo + hi) / 2, idx2 = (len1 + len2 + 1) / 2 - idx1;

            if (idx1 > 0 && nums1[idx1 - 1] > nums2[idx2]) hi = idx1 - 1;
            else if (idx1 < len1 && nums1[idx1] < nums2[idx2 - 1]) lo = idx1 + 1;
            else {
                if ((len1 + len2) % 2) {
                    if (idx1 == 0) return nums2[idx2 - 1];
                    else return max(nums1[idx1 - 1], nums2[idx2 - 1]);
                } else {
                    if (idx1 == 0) return (nums2[idx2 - 1] + min(nums1[idx1], (idx2 < len2 ? nums2[idx2] : INT_MAX))) / 2.0;
                    else if (idx1 == len1) return (max(nums1[idx1 - 1], idx2 > 0 ? nums2[idx2 - 1] : INT_MIN) + nums2[idx2]) / 2.0;
                    else return (max(nums1[idx1 - 1], nums2[idx2 - 1]) + min(nums1[idx1], nums2[idx2])) / 2.0;
                }
            }
        }

        return INT_MIN;
    }
};
