class Solution {
public:
int t[301];
 int n;
    unordered_set<string> st;

bool solve(int idx, string &s){
    if(idx == n){
        return true;
    }
    if(t[idx]!= -1){
        return t[idx];
    }

    if(st.find(s)!= st.end()){
         return true;
    }
     for (int l = 1; idx + l <= n; l++) {
string temp = s.substr(idx,l);
//string ko todhenge or idx se start krenge or l length tk leker jaynge ek ek karke 


     // Check if word exists in dictionary
            if (st.find(temp) != st.end() &&
                solve(idx + l, s)) {
   return t[idx] = true;
}
    }
    return t[idx] =  false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        

        n = s.length();
        memset(t , -1, sizeof(t));
        for(int i = 0 ; i< wordDict.size();i++){
            st.insert(wordDict[i]);
        }

        return solve(0,s);
    }
};