// Dynamic programming with retrieving solutions.
// Time: O(n^3), Space: O(n^2)

class Solution {
public:
    vector<string> solution;
    vector<string> results;
    
    bool Match(string & s, int begin, int end, string & w) {
        if (end - begin != w.size()) return false;
        
        for (int i = 0; i < w.size(); ++i) {
            if (s[begin + i] != w[i]) return false;
        }
        
        return true;
    }
    
    void RetrieveResults(string & s, vector<vector<int>> & dp, int end) {
        if (end == 0) {
            string tmp(solution[solution.size() - 1]);
            
            for (int i = solution.size() - 2; i >= 0; --i) tmp += " " + solution[i];
            
            results.push_back(tmp);
        }
        
        for (auto begin: dp[end]) {
            solution.push_back(s.substr(begin, end - begin));
            RetrieveResults(s, dp, begin);
            solution.pop_back();
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size() + 1, vector<int>());
        
        for (int end = 1; end <= s.size(); ++end) {
            for (auto & w: wordDict) {
                int begin = end - w.size();
                
                if (begin < 0) continue;
                
                if ((begin == 0 || dp[begin].size() > 0) && Match(s, begin, end, w)) dp[end].push_back(begin);
            }
        }
        
        RetrieveResults(s, dp, s.size());
        
        return results;
    }
};
