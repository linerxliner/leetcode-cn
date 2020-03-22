/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    const int kMod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& A) {
        int sum_subarray_mins = 0;
        deque<int> dq;
        vector<int> new_A(A.size() + 2);

        new_A[0] = new_A[new_A.size() - 1] = INT_MIN;
        for (int i = 1; i < new_A.size() - 1; ++i) new_A[i] = A[i - 1];

        for (int i = 0; i < new_A.size(); ++i) {
            while (!dq.empty() && new_A[dq.back()] > new_A[i]) {
                sum_subarray_mins += new_A[dq.back()] * (dq.back() - *(prev(dq.end(), 2))) * (i - dq.back());
                sum_subarray_mins %= kMod;
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return sum_subarray_mins;
    }
};
