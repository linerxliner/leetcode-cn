/* Complexity
 *   Time: O(max(m, n))
 *   Space: O(1)
 */

class Solution {
public:
    int ToInt(const string& version, int& end) {
        for (int begin = end; end <= version.size(); ++end) {
            if (end == version.size() || version[end] == '.') {
                return atoi(version.substr(begin, end).c_str());
            }
        }

        return 0;
    }

    int compareVersion(string version1, string version2) {
        int idx1 = 0, idx2 = 0;

        for (; idx1 <= version1.size() || idx2 <= version2.size(); ++idx1, ++idx2) {
            int v1_num, v2_num;

            if (idx1 <= version1.size() && idx2 <= version2.size()) {
                v1_num = ToInt(version1, idx1);
                v2_num = ToInt(version2, idx2);

                if (v1_num < v2_num) return -1;
                else if (v1_num > v2_num) return 1;
            } else if (idx1 <= version1.size()) {
                if (ToInt(version1, idx1) != 0) return 1;
            } else {
                if (ToInt(version2, idx2) != 0) return -1;
            }
        }

        return 0;
    }
};
