/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> result(digits.size(), 0);

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (carry) {
                result[i] = digits[i] + carry;
                if (result[i] >= 10) {
                    result[i] -= 10;
                    carry = 1;
                } else carry = 0;
            } else {
                for (; i >= 0; --i) result[i] = digits[i];
            }
        }

        if (carry == 1) result.insert(result.begin(), 1);

        return result;
    }
};
