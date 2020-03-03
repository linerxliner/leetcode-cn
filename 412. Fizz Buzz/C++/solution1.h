/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        
        for (int i = 0; i < n; ++i) {
            int n = i + 1;
            
            if (n % 15 == 0) result[i] = "FizzBuzz";
            else if (n % 5 == 0) result[i] = "Buzz";
            else if (n % 3 == 0) result[i] = "Fizz";
            else result[i] = to_string(n);
        }
        
        return result;
    }
};
