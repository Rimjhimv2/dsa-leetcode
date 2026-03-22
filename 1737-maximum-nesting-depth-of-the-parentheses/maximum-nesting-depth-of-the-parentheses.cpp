class Solution {
public:
    int maxDepth(string s) {
        int maxLength = 0;
        stack<char> st;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push('(');
                maxLength = max(maxLength, (int)st.size());
            }
            else if(s[i] == ')') {
                st.pop();
            }
        }

        return maxLength;
    }
};