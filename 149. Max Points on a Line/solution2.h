// Three point collinear method.
// Time: O(n ^ 3): Space: O(1)

class Solution {
public:    
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();
        
        int global_max = 0;
        
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 0;
            
            for (int j = i + 1; j < points.size(); ++j) {
                int local_max;
                long dy = points[i][1] - points[j][1], dx = points[i][0] - points[j][0], check_value = dy * points[j][0] - dx * points[j][1];;
                
                if (dy == 0 && dx == 0) {
                    local_max = 1;
                    ++duplicate;
                } else {
                    local_max = 2;
                    for (int k = j + 1; k < points.size(); ++k) {
                        if (dy * points[k][0] - dx * points[k][1] == check_value) ++local_max;
                    }
                }
                
                global_max = max(global_max, local_max + duplicate);
            }
        }
        
        return global_max;
    }
};
