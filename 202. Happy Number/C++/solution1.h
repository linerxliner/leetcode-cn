class Solution {
public:
    int order_square_num(int n) {
        int new_n = 0;
        
        while (n > 0) {
            int t = n % 10;

            new_n += t * t;
            n /= 10;
        }
        
        return new_n;
    }
    
    bool isHappy(int n) {
        int low = n, fast = n;
        
        do {
            low = order_square_num(low);
            fast = order_square_num(order_square_num(fast));
        } while (low != fast);
        
        if (low == 1) return true;
        
        return false;
    }
};
