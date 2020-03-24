/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;

        int n = start.size();

        for (int i = 0, j = 0; i < n && j < n; ++i, ++j) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;

            if ((i < n) ^ (j < n)) return false;

            if (i < n && j < n) {
                if (start[i] != end[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
            }
        }

        return true;
    }
};
