class Solution {
public:
    bool makeEqual(vector<string>& words) {

      int n = words.size();
      unordered_map<char,int>mp;
      for(string & word:words){
        for(char &ch: word){
            mp[ch]++;
        }
      }
      for(auto&it : mp){
        int freq = it.second;
        if(freq % n != 0 ){
            //Agar kisi character ki frequency strings ki count se divide nahi hoti, to sab strings equal nahi ban sakti.
            return false;
        }

      }
return true;
    }
}; 