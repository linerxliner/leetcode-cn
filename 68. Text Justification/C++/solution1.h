/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    string GenerateLine(bool last, vector<string>& line_words, int char_num, int maxWidth) {
        string answer = line_words[0];

        if (line_words.size() == 1) {
            while (answer.size() < maxWidth) answer += " ";
            return answer;
        }

        if (last) {
            for (int i = 1; i < line_words.size(); ++i) answer += " " + line_words[i];
            while (answer.size() < maxWidth) answer += " ";
        } else {
            int interval_num = line_words.size() - 1, blank_num = maxWidth - (char_num - interval_num);
            int longer_num = blank_num % interval_num, blank_len_per_interval = blank_num / interval_num;

            for (int i = 1; i < line_words.size(); ++i) {
                for (int j = 0; j < blank_len_per_interval + (i <= longer_num ? 1 : 0); ++j) answer += " ";
                answer += line_words[i];
            }
        }

        return answer;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> line_words;
        int char_num = 0;

        for (auto& w: words) {
            if (!line_words.empty() && char_num + 1 + w.size() > maxWidth) {
                result.push_back(GenerateLine(false, line_words, char_num, maxWidth));
                line_words.clear();
                char_num = 0;
            }

            char_num += (line_words.empty() ? 0 : 1) + w.size();
            line_words.push_back(w);
        }
        result.push_back(GenerateLine(true, line_words, char_num, maxWidth));

        return result;
    }
};
