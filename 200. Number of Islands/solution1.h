// BFS.
// Time: O(n * m), Space: O(n * m)

const int kDRC[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0; if (grid.empty()) return cnt;

        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == '1') {
                    ++cnt;
                    
                    queue<pair<int, int>> q;
                    
                    q.push(make_pair(r, c));
                    grid[r][c] = 0;
                    
                    while (!q.empty()) {
                        int u_r = q.front().first, u_c = q.front().second; q.pop();
                        
                        for (int i = 0; i < 4; ++i) {
                            int n_r = u_r + kDRC[i][0], n_c = u_c + kDRC[i][1];
                            
                            if (n_r >= 0 && n_r < grid.size() && n_c >= 0 && n_c < grid[0].size() && grid[n_r][n_c] == '1') {
                                q.push(make_pair(n_r, n_c));
                                grid[n_r][n_c] = 0;
                            }
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};
