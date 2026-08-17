class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        //ss mai aagye 

        string token;
        string result = "";

        while(ss>>token){
            //token mai aarhe sare word ek ek karke

            result = token + " " + result;
        }

        result.pop_back();

        return result ;
    }
};