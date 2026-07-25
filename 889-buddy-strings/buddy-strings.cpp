class Solution {
public:

//Ye function ka basic kaam sirf itna hai:
// Check karna ki string me koi bhi character repeat (duplicate) hua hai ya nahi.
// Agar duplicate mila → true
// Nahi mila → false

    bool checkFreq(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            //string ka har character ch mai aayega 
            freq[ch - 'a']++;
            //char ko index mai converrt karo 

            if (freq[ch - 'a'] >= 2) {
                return true;
            }
        }

        return false;
    }
    bool buddyStrings(string s, string goal) {
        
        if(s.length()!=goal.length()){
            return false;
        }
        //ager dono string ki length same nahi hai toh ek swap se dusre swap tak nahi pahuch sakte 

        if(s == goal){
            return checkFreq(s);
        }
        //ager dono string exactly equal hai to dekhna padhega ki kya  string ko swap krne baad bhi same rehta hai ya nhi 
        //esiliye checkfreq kiya hai 

        vector<int> index;
        for(int i = 0 ; i<s.length();i++){
            if(s[i]!= goal[i]){
                index.push_back(i);
            }
        }
        //buddy string mai 1 swap se exactly 2 mismatch hone chaiye
         if (index.size() != 2) {
            return false;
        }


         // Swap the mismatched characters
        swap(s[index[0]], s[index[1]]);

        return s == goal;

    }
};