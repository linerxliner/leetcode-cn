// Backtracking with memo of bad suffix.
// Time: O(n^2), Space: O(n)

class Solution {
public:
    map<int, bool> dp;
    
    bool BreakOneWord(string s, vector<string> & word_dict) {
        if (s.size() == 0) return true;
        else if (dp.count(s.size())) return dp[s.size()];
        
        for (auto & w: word_dict) {
            if (s.find(w) == 0 && BreakOneWord(s.substr(w.size(), s.size() - w.size()), word_dict)) return true;
        }
        
        return dp[s.size()] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return BreakOneWord(s, wordDict);
    }
};
