/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesis_stack;
        map<char, char> lr_parentheses = {{')', '('}, {']', '['}, {'}', '{'}};

        for (auto c: s) {
            if (c == '(' || c == '[' || c == '{') parenthesis_stack.push(c);
            else {
                if (parenthesis_stack.empty()) return false;
                else {
                    if (parenthesis_stack.top() == lr_parentheses[c]) parenthesis_stack.pop();
                    else return false;
                }
            }
        }

        return parenthesis_stack.empty();
    }
};
