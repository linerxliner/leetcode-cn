// DP
// Time: O(n^2), Space: O(n)

class Solution {
public:
    bool Match(string & s, int begin, int end, string & w) {
        if (end - begin != w.size()) return false;
        
        for (int i = 0; i < w.size(); ++i) {
            if (s[begin + i] != w[i]) return false;
        }
        
        return true;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        
        dp[0] = true;
        
        for (int end = 1; end <= s.size(); ++end) {
            for (int begin = end - 1; begin >= 0; --begin) {
                bool matched = false;
                
                if (dp[begin]) {
                    for (auto & w: wordDict) {
                        if (Match(s, begin, end, w)) {
                            dp[end] = true;
                            matched = true;
                            break;
                        }
                    }
                }
                
                if (matched) break;
            }
        }
        
        return dp[s.size()];
    }
};
