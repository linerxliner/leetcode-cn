/* Complexity
 *   Time: O(1)
 *   Space: O(1)
 */

class Solution {
public:
    vector<string> result;
    vector<string> solution;

    void DetectSegment(string& s, int begin, int d) {
        if (d == 4) {
            if (begin == s.size()) result.push_back(solution[0] + "." + solution[1] +  "." + solution[2] + "." + solution[3]);
            return;
        }

        for (int end = begin; end < s.size() && end - begin < 3; ++end) {
            int len = end - begin + 1;
            string segment = s.substr(begin, len);

            if ((len == 1 || (len > 1 && segment[0] != '0')) && atoi(segment.c_str()) <= 255) {
                solution[d] = s.substr(begin, end - begin + 1);
                DetectSegment(s, end + 1, d + 1);
            } else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solution = vector<string>(4);

        DetectSegment(s, 0, 0);

        return result;
    }
};
