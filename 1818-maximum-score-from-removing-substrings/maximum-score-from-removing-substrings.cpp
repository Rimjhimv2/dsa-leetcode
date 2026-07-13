class Solution {
public:      

    string removesubStr(string &s, string &matchStr){
      

       stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (!st.empty() &&
                st.top() == matchStr[0] &&
                s[i] == matchStr[1]) {

                st.pop();      // substring remove
            }
            else {
                st.push(s[i]);
            }
        }

        string temp = "";

        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }



    int maximumGain(string s, int x, int y) {

       int n= s.length();


 int score = 0;
       string maxSubstr, minSubstr;

if (x >= y) {
    maxSubstr = "ab";
    minSubstr = "ba";
} else {
    maxSubstr = "ba";
    minSubstr = "ab";
}

       //first pass
       string temp_first = removesubStr(s,maxSubstr);
       //matlab hamne full string se max string waala part yani ab hata rahe hai 
       int length = temp_first.length();
       //yaha se manlo 6 aaya 

       //ab pair nikalna hai 
       int charRemoved = n-length;//yaha se 8 aaya 

       score+= charRemoved/2 * max(x,y);

       




       //second pass

        string temp_second = removesubStr(temp_first,minSubstr);

        charRemoved = temp_first.length() - temp_second.length();

        score+= charRemoved/2 * min(x,y);

        return score;




    }
};