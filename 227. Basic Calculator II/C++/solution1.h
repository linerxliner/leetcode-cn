class Solution {
public:
    long ReadNum(string & s, int & i) {
        long num = 0;
        
        while (i < s.size() && s[i] == ' ') ++i;
        while (i < s.size() && isdigit(s[i])) num = num * 10 + s[i++] - '0';
        --i;
        
        return num;
    }
    
    int calculate(string s) {
        int result = 0;
        stack<long> num_stack;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) num_stack.push(ReadNum(s, i));
            else if (s[i] != ' ') {
                char op = s[i];
                long num = ReadNum(s, ++i);
                
                switch (op) {
                    case '+':
                        num_stack.push(num);
                        break;
                    case '-':
                        num_stack.push(-num);
                        break;
                    case '*':
                        num_stack.top() *= num;
                        break;
                    case '/':
                        num_stack.top() /= num;
                        break;
                    default: break;
                }
            }
        }
        
        while (!num_stack.empty()) {
            result += num_stack.top();
            num_stack.pop();
        }

        return result;
    }
};
