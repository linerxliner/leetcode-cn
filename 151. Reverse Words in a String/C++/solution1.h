/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    string reverseWords(string s) {
        int begin = 0, end = s.size() - 1;
        
        while (begin < s.size() && s[begin] == ' ') ++begin;
        while (end >= 0 && s[end] == ' ') --end;
        if (begin <= end) s = s.substr(begin, end - begin + 1);
        else return "";
        
        for (begin = 0, end = 0; end < s.size(); ++begin, ++end) {
            s[begin] = s[end];
            while (s[end] == ' ' && s[end + 1] == ' ') ++end;
        }
        s = s.substr(0, begin);
        
        for (begin = 0, end = 0; end <= s.size(); ++end) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + begin, s.begin() + end);
                begin = end + 1;
            }
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};
