/* Complexity
 *   Time: O(n ^ 2)
 *   Space: O(n ^ 2)
 */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size(), cnt = 0;
        vector<bool> visited(N, false);
        
        for (int s = 0; s < N; ++s) {
            if (!visited[s]) {
                queue<int> q;
                
                q.push(s);
                while (!q.empty()) {
                    int u = q.front(); q.pop();

                    for (int v = 0; v < N; ++v) {
                        if (!visited[v] && M[u][v]) {
                            q.push(v);
                            visited[v] = true;
                        }
                    }
                }
                
                ++cnt;
            }
        }
        
        return cnt;
    }
};
