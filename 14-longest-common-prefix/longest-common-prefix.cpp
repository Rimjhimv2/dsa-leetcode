

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
    
//     for(int col = 0 ; col < strs[0].size(); col++){
//         char  ch = strs[0][col];

//         for(int row = 1 ; row < strs.size(); row++){
//             if(col >= strs[row].size() || strs[row][col] != ch){
//                 return strs[0].substr(0,col);
//             }
//         }
//     }
//     return strs[0];


//     }
// };




 class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {


int n = strs.size();
        string prefix = strs[0];
        for(int i = 1 ; i< n ; i++){
            int j = 0 ;
            while(j< strs[i].size() && j < prefix.size() && prefix[j]==strs[i][j]){
                j++;
            }

             prefix = prefix.substr(0,j);

        if(prefix == "") {
                return "";
            }
        }

        return prefix;


}
};