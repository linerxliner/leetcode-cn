/* Complexity
 *   Time: O(4 ^ n / (n ^ (2 / 3)))
 *   Space: O(4 ^ n / (n ^ (2 / 3)))
 * Description
 *   DFS with backtracking.
 */

class Solution {
public:
    vector<string> result;
    string answer;
    
    void RGenerate(int unmatched, int unused) {
        if (unmatched == 0 && unused == 0) {
            result.push_back(answer);
            return;
        }
        
        if (unused > 0) {
            answer.push_back('(');
            RGenerate(unmatched + 1, unused - 1);
            answer.pop_back();
        }
        
        if (unmatched > 0) {
            answer.push_back(')');
            RGenerate(unmatched - 1, unused);
            answer.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        RGenerate(0, n);
        
        return result;
    }
};
