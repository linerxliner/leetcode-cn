/* Complexity
 *   Time: O(m + n)
 *   Space: O(1)
 * Description
 *   Finds ((m + n + 1) / 2)-th number by eliminating half of k numbers.
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int begin1 = 0, begin2 = 0, len1 = nums1.size(), len2 = nums2.size(), k = (len1 + len2 + 1) / 2;
        bool even = (len1 + len2) % 2 == 0;

        while (true) {
            int len = k / 2, end1 = min(len1, begin1 + len), end2 = min(len2, begin2 + len);

            if (begin1 >= len1) {
                if (even) return (nums2[begin2 + k - 1] + nums2[begin2 + k]) / 2.0;
                else return nums2[begin2 + k - 1];
            } else if (begin2 >= len2) {
                if (even) return (nums1[begin1 + k - 1] + nums1[begin1 + k]) / 2.0;
                else return nums1[begin1 + k - 1];
            } else if (k == 1) {
                int k_num = min(nums1[begin1], nums2[begin2]);

                if (even) return (k_num + min(max(nums1[begin1], nums2[begin2]), min(begin1 + 1 < len1 ? nums1[begin1 + 1] : INT_MAX, begin2 + 1 < len2 ? nums2[begin2 + 1] : INT_MAX))) / 2.0;
                else return k_num;
            } else {
                if (nums1[end1 - 1] <= nums2[end2 - 1]) {
                    k -= end1 - begin1;
                    begin1 = end1;
                } else {
                    k -= end2 - begin2;
                    begin2 = end2;
                }
            }
        }
    }
};
