// Carry recursive addition.
// Time: O(1), Space: O(1)

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int t = (unsigned int)(a & b) << 1;
            
            a ^= b;
            b = t;
        }
        
        return a;
    }
};
