class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, bool> memo;

    bool isConcatenated(string word) {

        if (memo.count(word))
            return memo[word];

        int n = word.length();

        for (int i = 1; i < n; i++) {

            string prefix = word.substr(0, i);
            string suffix = word.substr(i);

            // prefix aur suffix dono dictionary me hain
            if (st.count(prefix) && st.count(suffix))
                return memo[word] = true;

            // prefix dictionary me hai aur suffix ko aur break kar sakte hain
            if (st.count(prefix) && isConcatenated(suffix))
                return memo[word] = true;
        }

        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        st.insert(words.begin(), words.end());

        vector<string> ans;

        for (string word : words) {

            st.erase(word);   // khud ko use nahi karne dena

            if (isConcatenated(word))
                ans.push_back(word);

            st.insert(word);  // wapas add kar do
        }

        return ans;
    }
};