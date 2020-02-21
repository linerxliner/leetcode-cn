class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        
        if (numerator != 0 && ((numerator >= 0) ^ (denominator >= 0))) result.push_back('-');
        long num = abs(long(numerator));
        long denom = abs(long(denominator));
        
        int integer_len;
        long integer = num / denom, remainder = num % denom;
        unordered_map<long, int> remainder_record;
        
        result += to_string(integer);
        integer_len = result.size();
        
        for (int i = 0; remainder > 0; ++i) {
            if (i == 0) result += ".";
            
            remainder_record[remainder] = integer_len + 1 + i;
            
            result.push_back(remainder * 10 / denom + '0');
            remainder = remainder * 10 % denom;
            
            if (remainder_record.count(remainder) > 0) {
                result.insert(remainder_record[remainder], "(");
                result.push_back(')');
                break;
            }
        }
        
        return result;
    }
};
