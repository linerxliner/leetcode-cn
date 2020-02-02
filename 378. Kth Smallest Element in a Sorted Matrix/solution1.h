class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix.back().back();

        while (lo < hi) {
            int mi = (lo + hi + 1) >> 1;
            int cnt = 0, row = 0, column = matrix[0].size() - 1;
            
            while (row < matrix.size() && column >= 0) {
                if (matrix[row][column] < mi) {
                    cnt += column + 1;
                    ++row;
                } else --column;
            }
            
            if (cnt < k) lo = mi;
            else hi = mi - 1;
        }
        
        return lo;
    }
};
