const int kLetterNum = 26;

class Solution {
public:
    int cnt[kLetterNum];
    
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        
        for (int i = 0; i < kLetterNum; ++i) {
            if (cnt[i] != 0) return false;
        }
        
        return true;
    }
};
