class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        

        int m = s1.length();
        int n = s2.length();

        if(m>n)return false;
        sort(s1.begin(),s1.end());

        for(int i = 0 ; i<=n-m ; i++){
             string subS = s2.substr(i,m);
         sort(subS.begin(),subS.end());
             if(s1==subS){
                return true;
             }
        }
        return false;
    }
};