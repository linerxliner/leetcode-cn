class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        
        while (l <= r) {
            while (l < s.size() && !isalnum(s[l])) ++l;
            while (r >= 0 && !isalnum(s[r])) --r;
            
            if (r < l) return true;
            else if (tolower(s[l]) == tolower(s[r])) {
                ++l;
                --r;
            } else return false;
        }
        
        return true;
    }
};
