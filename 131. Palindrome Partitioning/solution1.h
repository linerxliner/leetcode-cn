class Solution {
public:
    vector<vector<string>> results;
    vector<string> solution;
    
    vector<vector<int>> DetectPalindromes(string & s) {
        vector<vector<int>> dp(s.size(), vector<int>());
        
        for (int i = 0; i < s.size(); ++i) {
            for (int l = 0; i - l >= 0 && i + l < s.size(); ++l) {
                if (s[i - l] == s[i + l]) dp[i - l].push_back(i + l);
                else break;
            }
            for (int l = 0; i - l >= 0 && i + 1 + l < s.size(); ++l) {
                if (s[i - l] == s[i + 1 + l]) dp[i - l].push_back(i + 1 + l);
                else break;
            }
        }
        
        return dp;
    }
    
    void PalindromePartitioning(vector<vector<int>> & dp, string & s, int begin) {
        if (begin == s.size()) {
            results.push_back(solution);
            return;
        }
        
        for (auto end: dp[begin]) {
            solution.push_back(s.substr(begin, end - begin + 1));
            PalindromePartitioning(dp, s, end + 1);
            solution.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<int>> dp = DetectPalindromes(s);
        PalindromePartitioning(dp, s, 0);
        return results;
    }
};
