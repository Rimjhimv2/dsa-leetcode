class Solution {
public:

    bool solve(int i, int j, string &s, string &p) {

        // Pattern bhi khatam aur string bhi
        // chevk karta kya s ka i se end tak ka part and p se j tak ka part match karta hai ya nahi 
        if (i == s.size() && j == p.size())
            return true;

        // Pattern khatam lekin string baaki
        if (j == p.size())
            return false;

        // Current character match?
        bool firstMatch = (i < s.size() &&
                          (s[i] == p[j] || p[j] == '.'));
                          //ans true or false mai hi aayega 

        // Next character '*' hai?
        if (j + 1 < p.size() && p[j + 1] == '*') {
            //first character a hai and dusra char * hai esiliye j+1 se start kara ahi 

            // 0 occurrence OR 1/more occurrence
            return solve(i, j + 2, s, p) ||
                   (firstMatch && solve(i + 1, j, s, p));
        }

        // Normal character
        if (firstMatch)
            return solve(i + 1, j + 1, s, p);

        return false;
    }

    bool isMatch(string s, string p) {

        return solve(0, 0, s, p);
    }
};