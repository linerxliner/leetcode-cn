/* Complexity
 *   Time: O(n ^ 4)
 *   Space: O(n ^ 3)
 */

class Solution {
public:
    unordered_map<string, int> memo;

    int DP(int prev_num, int begin, int end, vector<int>& boxes, vector<int>& right) {
        string state = to_string(prev_num) + "," + to_string(begin) + "," + to_string(end);
        if (memo.count(state) > 0) return memo[state];
        else if (begin >= end) return 0;

        int idx = begin;
        int answer = 0;

        ++prev_num;
        for (; idx < end - 1 && right[idx] == idx + 1; idx = right[idx]) ++prev_num;
        answer = max(answer, prev_num * prev_num + DP(0, idx + 1, end, boxes, right));

        begin = idx + 1;
        while (idx < end) {
            while (idx < end - 1 && right[idx] == idx + 1) idx = right[idx];
            if ((idx = right[idx]) >= end) break;
            answer = max(answer, DP(0, begin, idx, boxes, right) + DP(prev_num, idx, end, boxes, right));
        }

        return memo[state] = answer;
    }

    int removeBoxes(vector<int>& boxes) {
        unordered_map<int, int> indexes;
        vector<int> right(boxes.size(), boxes.size());

        for (int i = boxes.size() - 1; i >= 0; --i) {
            if (indexes.count(boxes[i]) > 0) right[i] = indexes[boxes[i]];
            indexes[boxes[i]] = i;
        }

        return DP(0, 0, boxes.size(), boxes, right);
    }
};
