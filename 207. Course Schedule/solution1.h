enum State {kUndiscovered, kDiscovered, kVisited};

class Solution {
public:
    vector<vector<int>> adj;
    vector<State> states;
    
    bool DFS(int u) {
        states[u] = kDiscovered;
        
        for (auto v: adj[u]) {
            if (states[v] == kUndiscovered) {
                if (!DFS(v)) return false;
            }
            else if (states[v] == kDiscovered) return false;
        }
        
        states[u] = kVisited;
        
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses, vector<int>());
        states = vector<State>(numCourses, kUndiscovered);
        
        for (auto& edge: prerequisites) adj[edge[1]].push_back(edge[0]);
        
        for (int u = 0; u < numCourses; ++u) {
            if (!DFS(u)) return false;
        }
        
        return true;
    }
};
