class Solution {
public:
    bool isPowerOfThree(int n) {
        int max_power_of_three = int(pow(3, int(log(INT_MAX) / log(3))) + 0.00000001);
        
        return n > 0 && max_power_of_three % n == 0;
    }
};
