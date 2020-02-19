// Divide and conquer.
// Time: O(nlogn), Space: O(n)

class Solution {
public:
    vector<vector<int>> MergeSkylines(vector<vector<int>>& left, vector<vector<int>>& right) {
        int l = 0, r = 0, left_len = left.size(), right_len = right.size();
        int x, curr_height, prev_height = 0, left_height = 0, right_height = 0;
        vector<vector<int>> result;
        
        while (l < left_len || r < right_len) {
            if (l < left_len && (r >= right_len || left[l][0] < right[r][0])) {
                x = left[l][0];
                left_height = left[l][1];
                ++l;
            } else {
                x = right[r][0];
                right_height = right[r][1];
                ++r;
            }
            
            curr_height = max(left_height, right_height);
            
            if (curr_height != prev_height) {
                if (result.empty() || result[result.size() - 1][0] != x) result.push_back({x, curr_height});
                else result[result.size() - 1][1] = curr_height;
                
                prev_height = curr_height;
            }
        }
        
        return result;
    }
    
    vector<vector<int>> GetSkylines(vector<vector<int>>& buildings, int lo, int hi) {
        if (hi - lo == 0) return vector<vector<int>>();
        else if (hi - lo == 1) return vector<vector<int>>({{buildings[lo][0], buildings[lo][2]}, {buildings[lo][1], 0}});
        
        vector<vector<int>> left = GetSkylines(buildings, lo, (lo + hi) / 2), right = GetSkylines(buildings, (lo + hi) / 2, hi);
        
        return MergeSkylines(left, right);
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return GetSkylines(buildings, 0, buildings.size());
    }
};
