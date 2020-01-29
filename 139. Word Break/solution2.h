// BFS

class Solution {
public:
    bool Match(string & s, int begin, string & w) {
        if (s.size() < w.size()) return false;
        
        for (int i = 0; i < w.size(); ++i) {
            if (s[begin + i] != w[i]) return false;
        }
        
        return true;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> visited(s.size(), false);
        queue<int> q;
        
        visited[0] = true;
        q.push(0);
        
        while (!q.empty()) {
            int begin = q.front(); q.pop();
            
            for (auto & w: wordDict) {
                if (Match(s, begin, w)) {
                    if ((begin + w.size()) == s.size()) return true;
                    else if (!visited[begin + w.size()]) {
                        visited[begin + w.size()] = true;
                        q.push(begin + w.size());
                    }
                }
            }
        }
        
        return false;
    }
};
