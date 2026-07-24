class Solution {
public:
    vector<string> ans;

    void solve(string &s, int index, int part, string curr) {

        // Agar 4 parts ban gaye aur poori string use ho gayi
        if (part == 4 && index == s.size()) {
            curr.pop_back();           // Last '.' remove
            ans.push_back(curr);
            return;
        }

        // Invalid case
        if (part == 4 || index == s.size()) {
            return;
        }

        // 1, 2 aur 3 digit ke segment try karo
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {

            string temp = s.substr(index, len);

            // Leading zero allowed nahi hai
            if (temp.size() > 1 && temp[0] == '0')
                break;

            // Value 255 se badi nahi honi chahiye
            if (stoi(temp) > 255)
                continue;

            solve(s, index + len, part + 1, curr + temp + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {

        solve(s, 0, 0, "");

        return ans;
    }
};