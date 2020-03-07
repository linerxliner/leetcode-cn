/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 * Description
 *   Bi-Scan.
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int units = 0;
        vector<int> to_right(height.size(), 0);
        
        for (int i = 0, h = 0; i < height.size(); ++i) {
            if (h < height[i]) h = height[i];
            to_right[i] = h;
        }
        
        for (int i = height.size() - 1, h = 0; i >= 0; --i) {
            if (h < height[i]) h = height[i];
            units += min(h, to_right[i]) - height[i];
        }
        
        return units;
    }
};
