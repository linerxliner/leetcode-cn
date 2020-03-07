/* Complexity
 *   Time: O(n * log(n))
 *   Space: O(n)
 */

class Solution {
public:
    static bool Cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end(), Cmp);
        
        vector<vector<int>> new_intervals(1, intervals[0]);
        
        for (int i = 1;i < intervals.size(); ++i) {
            if (intervals[i][0] <= new_intervals.back()[1]) {
                if (new_intervals.back()[1] < intervals[i][1]) new_intervals.back()[1] = intervals[i][1];
            } else new_intervals.push_back(intervals[i]);
        }
        
        return new_intervals;
    }
};
