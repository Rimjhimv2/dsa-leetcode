class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int  n = s.length();
        int countA = 0;
        int countB = 0 ;

        for(int i = 0;i<n/2;i++ ){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' ||s[i]=='I' || s[i]=='O' ||s[i]=='U' ){

                countA++;
            }
        }

        for(int i = n/2 ;i<n;i++ ){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' ||s[i]=='I' || s[i]=='O' ||s[i]=='U' ){

                countB++;
            }
        }
if(countA == countB){
     return true;
}
   

return false;

    }
};