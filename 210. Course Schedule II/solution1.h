class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt = 0;
        vector<int> in_degrees(numCourses, 0), order;
        vector<vector<int>> adj(numCourses, vector<int>());
        queue<int> q;
        
        for (auto& p: prerequisites) {
            ++in_degrees[p[0]];
            adj[p[1]].push_back(p[0]);
        }
        
        for (int u = 0; u < numCourses; ++u) {
            if (in_degrees[u] == 0) q.push(u);
        }
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            
            ++cnt; order.push_back(u);
            for (auto v: adj[u]) {
                if (--in_degrees[v] == 0) q.push(v);
            }
        }
        
        return cnt == numCourses ? order : vector<int>();
    }
};
