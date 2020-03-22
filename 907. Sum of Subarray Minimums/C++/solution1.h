/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    const int kMod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& A) {
        int sum_subarray_mins = 0;
        stack<int> s;
        vector<int> new_A(A.size() + 2);

        new_A[0] = new_A[new_A.size() - 1] = INT_MIN;
        for (int i = 1; i < new_A.size() - 1; ++i) new_A[i] = A[i - 1];

        for (int i = 0; i < new_A.size(); ++i) {
            while (!s.empty() && new_A[s.top()] > new_A[i]) {
                int t = s.top(); s.pop();

                sum_subarray_mins += new_A[t] * (t - s.top()) * (i - t);
                sum_subarray_mins %= kMod;
            }
            s.push(i);
        }

        return sum_subarray_mins;
    }
};
