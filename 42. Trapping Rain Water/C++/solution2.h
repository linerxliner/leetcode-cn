/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 * Description
 *   Double points.
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int units = 0;
        int left_max = 0, right_max = 0;
        int l = 0, r = height.size() - 1;
        
        while (l <= r) {
            if (height[l] < height[r]) {
                left_max = max(left_max, height[l]);
                units += left_max - height[l];
                ++l;
            } else {
                right_max = max(right_max, height[r]);
                units += right_max - height[r];
                --r;
            }
        }
        
        return units;
    }
};
