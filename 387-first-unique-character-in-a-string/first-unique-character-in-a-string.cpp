class Solution {
public:
    int firstUniqChar(string s) {
        
        int freq[26] = {0};   // frequency array
        
        // Step 1: Count frequency
        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        
        // Step 2: Find first unique character
        for(int i = 0; i < s.length(); i++) {
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

