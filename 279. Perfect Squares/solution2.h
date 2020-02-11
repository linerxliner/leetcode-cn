// BFS.
// Time: O(n^(3/2)), Space: O(n)

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> discovered(n + 1, false);
        
        discovered[n] = true;
        q.push(n);
        
        for (int round = 0; !q.empty(); ++round) {
            int q_size = q.size();

            for (int i = 0; i < q_size; ++i) {
                int num = q.front(); q.pop();
                
                for (int j = int(sqrt(num)); j > 0; --j) {
                    int r = num - j * j;
                    
                    if (r == 0) return round + 1;
                    else if (r > 0 && !discovered[r]) q.push(r);
                }
            }
        }
        
        return -1;
    }
};
