class Solution {
public:
    string reverseParentheses(string s) {
        


       string curr = "";
       stack<string>st;
       int n = s.size();

       for(int i = 0 ; i<n ; i++){

        if(s[i]=='('){
            st.push(curr);
            curr= "";

        }
        else if(s[i]==')'){
            reverse(curr.begin(),curr.end());
            curr = st.top() + curr;
            st.pop();
        }
        else{
            curr += s[i];
        }
       }

       return curr;
    }
};