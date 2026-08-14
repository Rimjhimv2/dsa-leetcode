class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int l = 1; l<=n/2 ; l++){
            if(n%l == 0 ){
                int times = n/l;
                string pattern = s.substr(0,l);
                string newstr = "";
                while(times--){
                    newstr+=pattern;
                    if(s==newstr){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};