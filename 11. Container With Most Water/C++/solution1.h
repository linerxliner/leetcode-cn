/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            if (height[l] < height[r]) {
                max_area = max(max_area, (r - l) * height[l]);
                ++l;
            } else {
                max_area = max(max_area, (r - l) * height[r]);
                --r;
            }
        }

        return max_area;
    }
};
