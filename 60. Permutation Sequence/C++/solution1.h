/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> nums;
        vector<int> factorials(n);
        string result;
        
        --k;
        
        for (int i = 1; i <= n; ++i) nums.push_back('0' + i);
        factorials[0] = 1;
        for (int i = 1; i < n; ++i) factorials[i] = factorials[i - 1] * i;
        
        for (int i = n - 1; i >= 0; --i) {
            int nums_idx = k / factorials[i];
            char c = nums[nums_idx];
            
            result.push_back(c);
            nums.erase(nums.begin() + nums_idx);
            k -= nums_idx * factorials[i];
        }
        
        return result;
    }
};
