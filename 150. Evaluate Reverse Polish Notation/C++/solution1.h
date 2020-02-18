class Solution {
public:
    stack<int> s;
    
    int evalRPN(vector<string>& tokens) {
        for (auto& t: tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();
                
                switch (t[0]) {
                    case '+':
                        s.push(n1 + n2);
                        break;
                    case '-':
                        s.push(n1 - n2);
                        break;
                    case '*':
                        s.push(n1 * n2);
                        break;
                    case '/':
                        s.push(n1 / n2);
                }
            } else s.push(atoi(t.c_str()));
        }
        
        return s.top();
    }
};
