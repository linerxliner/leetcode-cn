// Vertical division.
// Time: O(n), Space: O(n)

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        result = ''
        if numerator * denominator < 0:
            result += '-'
        numerator, denominator = abs(numerator), abs(denominator)
        result += str(numerator // denominator)
        remainder = numerator % denominator
        
        if remainder != 0:
            idx = 0
            fraction = []
            remainder_indexes = {}
            while remainder != 0:
                remainder *= 10
                if remainder in remainder_indexes:
                    fraction.insert(remainder_indexes[remainder], '(')
                    fraction.append(')')
                    break
                else:
                    remainder_indexes[remainder] = idx
                    fraction.append(str(remainder // denominator))
                    remainder = remainder % denominator
                idx += 1
            result += '.' + ''.join(fraction)
        
        return result
        
