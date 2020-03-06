/* Complexity
 *   Time: O(n * m)
 *   Space: O(n + m)
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int begin = 0;
        vector<char> result(num1.size() + num2.size(), 0);
        string result_str;
        
        for (int i = num1.size() - 1; i >= 0; --i) {
            if (num1[i] == '0') continue;
            for (int j = num2.size() - 1; j >= 0; --j) {
                char product = (num1[i] - '0') * (num2[j] - '0');
                
                product += result[i + j + 1];
                result[i + j + 1] = product % 10;
                result[i + j] += product / 10;
            }
        }
        
        for (; result[begin] == 0; ++begin);
        for (; begin < result.size(); ++begin) result_str += to_string(result[begin]);
        
        return result_str;
    }
};
