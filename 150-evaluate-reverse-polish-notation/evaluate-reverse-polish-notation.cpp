class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<int>st;
        for(int i = 0 ; i< n ; i++){
            string token = tokens[i];
            if (token == "*" || token == "+" || token == "-" || token == "/")
            {

                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();
                if(token == "*"){
                    st.push(b*a);
                }
                else if(token == "+"){
                    st.push(b+a);
                }
                else if(token == "-"){
                    st.push(b-a);
                }
                else{
                    st.push(b/a);
                }
               
            }
            else{
             st.push(stoi(token));
            }
        }
        return st.top();
    }
};