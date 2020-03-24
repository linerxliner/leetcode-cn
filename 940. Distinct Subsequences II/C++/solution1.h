/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

class Solution {
public:
    const int kMod = 1e9 + 7;

    int distinctSubseqII(string S) {
        int prev_subseq_size = 1, subseq_size;
        unordered_map<char, int> prev_same_char_subseq_size;

        for (auto c: S) {
            subseq_size = 2 * prev_subseq_size % kMod;
            subseq_size = (subseq_size + kMod - prev_same_char_subseq_size[c]) % kMod;
            prev_same_char_subseq_size[c] = prev_subseq_size;
            prev_subseq_size = subseq_size;
        }

        return subseq_size - 1;
    }
};
