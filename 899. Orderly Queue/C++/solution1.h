/* Complexity
 *   Time: O(n ^ 2) (K == 1), O(n) (k != 1)
 *   Space: O(n)
 */

class Solution {
public:
    const int kLetterNum = 26;

    string orderlyQueue(string S, int K) {
        string answer;

        if (K == 1) {
            answer = S;
            for (int i = 1; i < S.size(); ++i) {
                string t = S.substr(i, S.size() - i) + S.substr(0, i);
                if (t < answer) answer = t;
            }
        } else {
            int cnt[kLetterNum] = {0};

            for (auto c: S) ++cnt[c - 'a'];
            for (int i = 0; i < kLetterNum; ++i) {
                for (int j = 0; j < cnt[i]; ++j) answer += 'a' + i;
            }
        }

        return answer;
    }
};
