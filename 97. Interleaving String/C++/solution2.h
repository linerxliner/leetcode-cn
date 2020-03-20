/* Complexity
 *   Time: O(m * n)
 *   Space: O(m * n)
 * Description
 *   BFS.
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> visited(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        queue<pair<int, int>> q;

        q.push(make_pair(0, 0));
        visited[0][0] = true;

        while (!q.empty()) {
            int r = q.front().first, c = q.front().second; q.pop();

            if (r == s1.size() && c == s2.size()) return true;
            if (r < s1.size() && !visited[r + 1][c] && s1[r] == s3[r + c]) {
                q.push(make_pair(r + 1, c));
                visited[r + 1][c] = true;
            }
            if (c < s2.size() && !visited[r][c + 1] && s2[c] == s3[r + c]) {
                q.push(make_pair(r, c + 1));
                visited[r][c + 1] = true;
            }
        }

        return false;
    }
};
