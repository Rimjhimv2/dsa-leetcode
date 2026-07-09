class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        


        
        vector<string>ans;
        
        int j = 0 ;
        //Lekin stream me numbers 1 se n aate hain, 0 se n-1 nahi.
        for(int i = 1 ; i<=n ; i++){

            if(j == target.size())
            break;

            if(i == target[j]){
              ans.push_back("Push");
              j++;
            }
            else{
                 ans.push_back("Push");
                  ans.push_back("Pop");
            }
        }
        return ans;

    }
};