/* Complexity
 *   Time: O(n * m * log(n * m))
 *   Space: O(n * m)
 */

class Solution {
public:
    static const int kMaxSize = 50;
    
    struct UnionFind {
        int parent[kMaxSize * kMaxSize], rank[kMaxSize * kMaxSize], size[kMaxSize * kMaxSize];
        
        UnionFind(int n) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 0;
                size[i] = 1;
            }
        }
        
        int Find(int u) {
            while (u != parent[u]) {
                parent[u] = parent[parent[u]];
                u = parent[u];
            }
            
            return u;
        }
        
        int Union(int u1, int u2) {
            int p1 = Find(u1), p2 = Find(u2);
            
            if (p1 == p2) return size[p1];
            else {
                if (rank[p1] <= rank[p2]) {
                    parent[p1] = p2;
                    size[p2] += size[p1];
                    if (rank[p1] == rank[p2]) ++rank[p2];
                    return size[p2];
                } else{
                    parent[p2] = p1;
                    size[p1] += size[p2];
                    return size[p1];
                }
            }
        }
    };
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int max_area = 0;
        UnionFind union_find(grid.size() * grid[0].size());
        
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    max_area = max(max_area , 1);
                    if (c + 1 < grid[0].size() && grid[r][c + 1]) max_area = max(max_area, union_find.Union(r * grid[0].size() + c, r * grid[0].size() + c + 1));
                    if (r + 1 < grid.size() && grid[r + 1][c]) max_area = max(max_area, union_find.Union(r * grid[0].size() + c, (r + 1) * grid[0].size() + c));
                }
            }
        }
        
        return max_area;
    }
};
