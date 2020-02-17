const int kLetterNum = 26;

class Solution {
public:
    int cnt[kLetterNum], first[kLetterNum];
    
    int firstUniqChar(string s) {
        int idx = -1;
        
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i] - 'a'] == 0) first[s[i] - 'a'] = i;
            ++cnt[s[i] - 'a'];
        }
        for (int i = 0; i < kLetterNum; ++i) {
            if (cnt[i] == 1 && (idx == -1 || first[i] < idx)) idx = first[i];
        }
        
        return idx;
    }
};
