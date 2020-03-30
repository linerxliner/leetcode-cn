/* Complexity
 *   Time: O(m * n ^ 2)
 *   Space: O(n)
 */

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int min_steps = INT_MAX, ring_len = ring.size(), key_len = key.size();
        unordered_map<char, vector<int>> char2idx;
        vector<int> prev_dp(ring_len, INT_MAX);

        for (int i = 0; i < ring_len; ++i) {
            if (char2idx.count(ring[i]) == 0) char2idx[ring[i]] = vector<int>();
            char2idx[ring[i]].push_back(i);
        }

        for (auto to: char2idx[key[0]]) prev_dp[to] = min(to, ring_len - to) + 1;

        for (int i = 1; i < key_len; ++i) {
            vector<int> curr_dp(ring_len, INT_MAX);

            for (auto to: char2idx[key[i]]) {
                for (auto from: char2idx[key[i - 1]]) {
                    int dist = (from - to + ring_len) % ring_len;

                    curr_dp[to] = min(curr_dp[to], prev_dp[from] + min(dist, ring_len - dist) + 1);
                }
            }

            prev_dp = curr_dp;
        }

        for (auto ms: prev_dp) min_steps = min(min_steps, ms);

        return min_steps;
    }
};
