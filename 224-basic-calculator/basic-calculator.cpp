class Solution {
public:
    int calculate(string s) {

        stack<long long> st;

        long long result = 0;
        long long num = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Build multi-digit number
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // '+' operator
            else if (ch == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }

            // '-' operator
            else if (ch == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }

            // Opening parenthesis
            else if (ch == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            // Closing parenthesis
            else if (ch == ')') {

                result += sign * num;
                num = 0;

                long long prevSign = st.top();
                st.pop();

                long long prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }

            // Ignore spaces
            else if (ch == ' ') {
                continue;
            }
        }

        // Add the last number
        result += sign * num;

        return (int)result;
    }
};