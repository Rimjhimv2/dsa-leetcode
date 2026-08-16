class Solution {
public:
    string frequencySort(string s) {
        
        //sabse phle map banao 
        unordered_map<char,int>freq;

        for(char ch : s){
            freq[ch]++;
        }
        //ab map se sort nhi hota toh vector banao 

      vector<pair<int, char>> v;
        for(auto& [ch,count] : freq)//freq mai char value pair hai na esiliye 
        {
            v.push_back({count,ch});
        }
        sort(v.rbegin(), v.rend());

        //ab sort hogya build ans 

        string ans;
        for(auto &[count,ch] : v){
          ans.append(count, ch);
        }
        return ans;
    }
};