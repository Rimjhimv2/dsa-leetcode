class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> freq(26, 0);
        
        // Step 1: Count frequency
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        
        // Step 2: Find first unique character
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};

//🎯 Simple Summary
//Starting se continuously +1 wale numbers lo
//Unka sum nikalo
//Sum se start karke check karo kaunsa number missing hai

