class Solution {
public:
    int calculate(string s) {

        stack<long long> st;

        long long result = 0;
        long long sign = 1;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (isdigit(ch)) {

                long long num = 0;

                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                result += sign * num;
                i--;
            }

            else if (ch == '+') {
                sign = 1;
            }

            else if (ch == '-') {
                sign = -1;
            }

            else if (ch == '(') {

                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (ch == ')') {

                long long prevSign = st.top();
                st.pop();

                long long prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }

        return (int)result;
    }
};