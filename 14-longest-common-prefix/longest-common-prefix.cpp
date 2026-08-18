// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
        

//         string prefix = strs[0];
//         //flower hai 
//         //ab hame dekhna hai ki flower bhi baki string ka prefix hia ya nahi 
//         for(int i = 1 ; i<strs.size();i++
//         ){
//            while(strs[i].find(prefix) !=0){
//             //kya flower word flow ke anfder hai or ager nahi tab tak loop vchalega last ke ek lettrt pop back se 
//                 prefix.pop_back();
//            } 

//            if (prefix.empty()) { return ""; }
//         }

//         return prefix;
//     }
// };



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
    for(int col = 0 ; col < strs[0].size(); col++){
        char  ch = strs[0][col];

        for(int row = 1 ; row < strs.size(); row++){
            if(col >= strs[row].size() || strs[row][col] != ch){
                return strs[0].substr(0,col);
            }
        }
    }
    return strs[0];


    }
};