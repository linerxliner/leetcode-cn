// Adder.
// Time: O(1), Space: O(1)

class Solution {
public:
    int getSum(int a, int b) {
        int result = 0, c = 0;
        
        for (int i = 0; i < 32; ++i) {
            int a_bit = a & 0x1, b_bit = b & 0x1;
            
            result |= (a_bit ^ b_bit ^ c) << i;
            c = (a_bit & b_bit) | ((a_bit ^ b_bit) & c);
            
            a >>= 1; b >>= 1;
        }
        
        return result;
    }
};
