// Scans buildings with keeping current max height.
// Time: O(n), Space: O(n)

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int prev_height = 0;
        vector<pair<int, int>> vertical_edges;
        multiset<int> heights;
        vector<vector<int>> result;
        
        for (int i = 0; i < buildings.size(); ++i) {
            vertical_edges.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            vertical_edges.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(vertical_edges.begin(), vertical_edges.end());
        
        heights.insert(0);
        for (auto& ve: vertical_edges) {
            int curr_max_height;
            
            if (ve.second < 0) heights.insert(-ve.second);
            else heights.erase(heights.find(ve.second));
            
            curr_max_height = *heights.rbegin();
            
            if (curr_max_height != prev_height) {
                result.push_back({ve.first, curr_max_height});
                prev_height = curr_max_height;
            }
        }
        
        return result;
    }
};
