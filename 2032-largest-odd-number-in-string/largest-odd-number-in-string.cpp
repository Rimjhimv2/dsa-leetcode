class Solution {
public:
    string largestOddNumber(string num) {
      int n = num.size();
      for(int i = num.size()-1 ; i>=0 ; i--){
        // if(i/2 !=0){

        // }
        if((num[i]-'0') % 2 != 0 ){
            return num.substr(0,i+1);
        }
      }
      return "";
    }
};