class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int balance = 0 ; 
        int n = s.size();
//we traverse the array only once so the tc = o(n) and we use only extra variables like ans,balance so sc = O(1);
        for(int i = 0 ; i< n ; i++){
            if(s[i]=='('){
                balance++;
            }

            else{
                if(balance>0){
                    balance--;
                }
                else{
                    ans++;
                }
            }

        }
        ans+=balance;
        return ans;

    }
};