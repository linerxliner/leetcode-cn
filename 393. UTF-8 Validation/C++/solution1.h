/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); ++i) {
            int len = 0;
            
            for (int j = 7; j >= 0; --j) {
                if ((data[i] >> j) & 0x1) ++len;
                else break;
            }
            if (len == 1 || len > 4) return false;
            else if (len > 0) --len;
            
            if (i + len >= data.size()) return false;
            
            while (len--) {
                ++i;
                if (!(((data[i] >> 7 & 0x1) == 1) && ((data[i] >> 6 & 0x1) == 0))) return false;
            }
        }
        
        return true;
    }
};
