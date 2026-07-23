class Solution {
public:
    string countAndSay(int n) {

        string result = "1";
        for(int i = 2;i<=n;i++){
            string temp ="";
            int j =0;
            while(j<result.length()){
                int count = 0;
                char digit = result[j];

                while(j<result.length() && result[j]==digit){
                    count++;
                    j++;
                }

                 temp += to_string(count);
            temp+=digit;

            }

         

            result= temp;

        }
        return result;
        
    }
};