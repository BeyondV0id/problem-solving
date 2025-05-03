class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            if (isOperator(token)) {
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                int result = evaluate(token[0], num1, num2);
                stk.push(result);
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }

private:
    bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int evaluate(char op, int a, int b) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return a / b;
    }
};
