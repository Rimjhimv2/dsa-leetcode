// class Solution {
// public:
//     int numberOfSubstrings(string s) {
        
//         int n = s.size();
//         int ans =0;

//       int last[3] = {-1, -1, -1};

//         for(int i = 0 ; i< n ; i++){

//             last[s[i]-'a'] = i;

//              if(last[0]!=-1 
//              && last[1]!=-1 
//              && last[2] != -1){

//             ans += min({last[0],last[1], last[2]}) + 1;
//         }
//         }

       
//         return ans;
//     }
// };



 class Solution {
 public:
    int numberOfSubstrings(string s) {
        
        int freq[3] = {0, 0, 0};
  int left = 0 ;
        int ans = 0 ; 
        int n = s.size();

        for(int right = 0 ; right < n ; right++){
            freq[s[right] - 'a']++;


            while(freq[0] > 0 && freq[1] > 0 && freq[2 ] > 0 ){
                ans += n - right;

                  freq[s[left] - 'a']--;
            left++;

            }

           
          
        }
               return ans;
           }
 };