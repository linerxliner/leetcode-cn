/* Complexity
 *   Time: O(max(m, n))
 *   Space: O(1)
 */

class Solution {
public:
    const int kLetterNum = 26;
    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        int s1_cnt[kLetterNum] = {0}, s2_cnt[kLetterNum] = {0};
        
        for (auto c: s1) ++s1_cnt[c - 'a'];
        for (int i = 0; i < s1.size() - 1; ++i) ++s2_cnt[s2[i] - 'a'];
        
        for (int i = s1.size() - 1; i < s2.size(); ++i) {
            ++s2_cnt[s2[i] - 'a'];
            if (memcmp(s1_cnt, s2_cnt, sizeof(int) * kLetterNum) == 0) return true;
            --s2_cnt[s2[i - s1.size() + 1] - 'a'];
        }
        
        return false;
    }
};
