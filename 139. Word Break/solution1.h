// Backtracking with memo of bad suffix.
// Time: O(n^2), Space: O(n)

class Solution {
public:
    map<int, bool> dp;
    
    bool Match(string & s, int begin, string & w) {
        if (s.size() - begin < w.size()) return false;
        
        for (int i = 0; i < w.size(); ++i) {
            if (s[begin + i] != w[i]) return false;
        }
        
        return true;
    }
    
    bool BreakOneWord(string & s, int begin, vector<string> & word_dict) {
        if (begin == s.size()) return true;
        else if (dp.count(begin)) return dp[begin];
        
        for (auto & w: word_dict) {
            if (Match(s, begin, w) && BreakOneWord(s, begin + w.size(), word_dict)) return true;
        }
        
        return dp[begin] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return BreakOneWord(s, 0, wordDict);
    }
};
