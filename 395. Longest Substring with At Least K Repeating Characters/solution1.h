const int kLetterNum = 26;

class Solution {
public:
    int Count(string& s, int begin, int end, int k, vector<vector<int>>& dp) {
        if (end < begin) return 0;
        
        vector<int> count(kLetterNum);
        
        if (begin > 0) {
            for (int i = 0; i < kLetterNum; ++i) count[i] = dp[end][i] - dp[begin - 1][i];
        } else count = dp[end];
        
        for (; begin <= end && count[s[begin] - 'a'] < k; ++begin);
        for (; begin <= end && count[s[end] - 'a'] < k; --end);
        
        for (int mid = begin; mid <= end; ++mid) {
            if (count[s[mid] - 'a'] < k) return max(Count(s, begin, mid - 1, k, dp), Count(s, mid + 1, end, k, dp));
        }
        
        return end - begin + 1;
    }
    
    int longestSubstring(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(kLetterNum, 0));
        
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0) dp[i] = dp[i - 1];
            ++dp[i][s[i] - 'a'];
        }
        
        return Count(s, 0, s.size() - 1, k, dp);
    }
};
