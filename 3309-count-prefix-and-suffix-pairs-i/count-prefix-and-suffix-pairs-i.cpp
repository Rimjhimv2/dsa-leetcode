class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                string str1 = words[i];
                string str2 = words[j];

                if(str1.length() > str2.length()) continue;

                if(str2.find(str1) == 0 && 
                   str2.rfind(str1) == str2.length() - str1.length()){
                    count++;
                }
            }
        }

        return count;
    }
};
//tumhe kya karna hai 
// har choti string ko badi string se comp[are karna hai or dekhhna hai ki choti string badi sring mai prefix and suffix dono m presesnt hai naa
// agar hai to count increase kardo 
// otherwise nahi ]
//or base case str1 ka length less hona chiaye str2 se 
