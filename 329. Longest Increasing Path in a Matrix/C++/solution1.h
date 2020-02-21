class Solution {
public:
    vector<vector<int>> kDRC = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int lip = 0;
        vector<vector<int>> out_degrees(matrix.size(), vector<int>(matrix[0].size(), 0));
        queue<pair<int, int>> q;
        
        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                for (auto drc: kDRC) {
                    int n_r = r + drc[0], n_c = c + drc[1];

                    if (n_r >= 0 && n_r < matrix.size() && n_c >= 0 && n_c < matrix[0].size() && matrix[n_r][n_c] > matrix[r][c]) ++out_degrees[r][c];
                }
            }
        }
        
        for (int r = 0; r < matrix.size(); ++r) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                if (out_degrees[r][c] == 0) q.push(make_pair(r, c));
            }
        }
        
        while (!q.empty()) {
            int q_size = q.size();
            
            ++lip;
            for (int i = 0; i < q_size; ++i) {
                int r = q.front().first, c = q.front().second; q.pop();
                
                for (auto drc: kDRC) {
                    int n_r = r + drc[0], n_c = c + drc[1];

                    if (n_r >= 0 && n_r < matrix.size() && n_c >= 0 && n_c < matrix[0].size() && matrix[n_r][n_c] < matrix[r][c]) {
                        if (--out_degrees[n_r][n_c] == 0) q.push(make_pair(n_r, n_c));
                    }
                }
            }
        }
        
        return lip;
    }
};
