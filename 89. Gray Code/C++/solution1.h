/* Complexity
 *   Time: O(2 ^ n)
 *   Space: O(2 ^ n)
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        int msb = 1;
        vector<int> result = {0};

        while (n--) {
            int size = result.size();

            while (size--) result.push_back(result[size] + msb);
            msb <<= 1;
        }

        return result;
    }
};
