// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         int result = -1;
//         int n = s.size();
//         for(int i = 0; i<=n-2;i++){
//             for(int j = i+1; j<n;j++){

//                 if(s[i]==s[j]){
//                     result = max(result,j-i-1);
//                 }
//             }
//         }
//         return result;
//     }
// };


///better approchh 

 class Solution {
     public:
    int maxLengthBetweenEqualCharacters(string s) {

         unordered_map<char,int>mp;
        int n = s.size();
        int result = -1;
        for(int i = 0 ;  i<n ; i++){

            char ch = s[i];
            if(mp.find(ch)==mp.end()){
                mp[ch]=i;
            }
            else{
                result = max(result,i-mp[ch]-1);
            }

        }
        return result ;

    }
 };




////🧠 Logic kya hai?

//Agar kisi character ka:

//first index = i

////last index = j

// Toh beech ka length =

////j - i - 1

//Hume maximum length find karni hai.