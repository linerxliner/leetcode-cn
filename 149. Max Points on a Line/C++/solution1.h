// Spot-slope method.
// Time: O(n ^ 2), Space: O(n ^ 2)

class Solution {
public:
    int GCD(int a, int b) {
        int t;
        
        while (b != 0) {
            t = a % b;
            a = b;
            b = t;
        }
        
        return a;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int global_max_point_num = 0;
        
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 0, local_max_point_num = 0;
            unordered_map<string, int> k_count;
            
            for (int j = i + 1; j < points.size(); ++j) {
                int dy = points[i][1] - points[j][1], dx = points[i][0] - points[j][0];
                
                if (dy == 0 && dx == 0) {
                    ++duplicate;
                    continue;
                }
                
                int gcd = GCD(dy, dx);
                string k = to_string(dy / gcd) + "/" + to_string(dx / gcd);
                
                ++k_count[k];
                local_max_point_num = max(local_max_point_num, k_count[k]);
            }
            
            global_max_point_num = max(global_max_point_num, local_max_point_num + duplicate + 1);
        }
        
        return global_max_point_num;
    }
};
