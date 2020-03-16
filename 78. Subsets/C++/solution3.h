/* Complexity
 *   Time: O(2 ^ n)
 *   Space: O(2 ^ n)
 * Description
 *   Adds element to prev subsets.
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        
        for (auto n: nums) {
            int len = result.size();
            
            for (int i = 0; i < len; ++i) {
                vector<int> subset = result[i];
                
                subset.push_back(n);
                result.push_back(subset);
            }
        }
        
        return result;
    }
};
