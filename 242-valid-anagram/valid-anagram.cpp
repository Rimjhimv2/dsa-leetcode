// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(begin(s),end(s));
//         sort(begin(t),end(t));

//         return s==t;
        
//     }
// };

class Solution {
 public:
    bool isAnagram(string s, string t) {
        
//base case
if(s.length()!= t.length()){
    return false;
}
  unordered_map<char, int> mp;
  for(int i = 0 ; i<s.length();i++){
    mp[s[i]]++;
  }
  for(int i = 0 ; i<t.length();i++){
    mp[t[i]]--;
  
if (mp[t[i]] < 0) {
                return false;
            }
        }

        return true;
  }
  
   };