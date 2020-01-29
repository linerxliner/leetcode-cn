// Backtrakcing with memo of bad suffix.
// Time: O(n^3), Space: O(n^2)

class Solution {
public:
    set<int> bad_memo;
    vector<string> solution;
    vector<string> results;
    
    bool Match(string & s, int begin, string & w) {
        if (s.size() - begin < w.size()) return false;
        
        for (int i = 0; i < w.size(); ++i) {
            if (s[begin + i] != w[i]) return false;
        }
        
        return true;
    }
    
    bool BreakOneWord(string & s, int begin, vector<string> & word_dict) {
        bool broken = false;
        
        if (begin == s.size()) {
            string tmp;
            
            tmp += solution[0];
            for (int i = 1; i < solution.size(); ++i) tmp += " " + solution[i];
            
            results.push_back(tmp);
            
            return true;
        } else if (bad_memo.count(begin) > 0) return false;
        
        for (auto & w: word_dict) {
            if (Match(s, begin, w)) {
                solution.push_back(w);
                if (BreakOneWord(s, begin + w.size(), word_dict)) broken = true;
                solution.pop_back();
            }
        }
        
        if (!broken) bad_memo.insert(begin);
        
        return broken;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        BreakOneWord(s, 0, wordDict);
        
        return results;
    }
};
