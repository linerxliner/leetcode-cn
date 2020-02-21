// Union find.
// Time: O(n * m * log(n * m)), Space: O(n * m)

const int kDRC[][2] = {{0, 1}, {1, 0}};

class Solution {
public:
    int row_num, column_num;
    
    struct UnionFind {
        int union_num;
        vector<int> parent, rank;
        
        UnionFind(int n) {
            for (int i = 0; i < n; ++i) {
                parent.push_back(i);
                rank.push_back(0);
            }
            union_num = n;
        }
        
        int Find(int idx) {
            while (idx != parent[idx]) {
                parent[idx] = parent[parent[idx]];
                idx = parent[idx];
            }
            
            return idx;
        }
        
        void Union(int idx1, int idx2) {
            int r1 = Find(idx1), r2 = Find(idx2);
            
            if (r1 == r2) return;
            else {
                if (rank[r1] < rank[r2]) parent[r1] = r2;
                else if (rank[r1] > rank[r2]) parent[r2] = r1;
                else {
                    parent[r1] = r2;
                    ++rank[r2];
                }
                --union_num;
            }
        }
    };
    
    inline int GetIdx(int r, int c) {
        return r * column_num + c;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        row_num = grid.size(); column_num = grid[0].size();
        int n = row_num * column_num + 1;
        UnionFind union_find(n);
        
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == '0') union_find.Union(GetIdx(r, c), n - 1);
                else {
                    for (int i = 0; i < 2; ++i) {
                        int n_r = r + kDRC[i][0], n_c = c + kDRC[i][1];
                        
                        if (n_r < grid.size() && n_c < grid[0].size() && grid[n_r][n_c] == '1') union_find.Union(GetIdx(r, c), GetIdx(n_r, n_c));
                    }
                }
            }
        }
        
        return union_find.union_num - 1;
    }
};
