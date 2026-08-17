// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream ss(s);
//         //ss mai aagye 

//         string token;
//         string result = "";

//         while(ss>>token){
//             //token mai aarhe sare word ek ek karke

//             result = token + " " + result;
//         }

//         result.pop_back();

//         return result ;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {

        // Step 1: poori string reverse
        reverse(s.begin(), s.end());

        int i = 0;

        // l = current word ka starting point
        // r = answer mein next position
        int l = 0, r = 0;

        int n = s.length();

        while (i < n) {

            // Spaces ko skip karo
            while (i < n && s[i] == ' ') {
                i++;
            }

            // Current word ko compact position par copy karo
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }

            // Agar word mila
            if (l < r) {

                // Word ko reverse karo
                reverse(s.begin() + l, s.begin() + r);

                // Words ke beech single space
                s[r] = ' ';
                r++;

                // Next word ka starting point
                l = r;
            }
        }

        // Last extra space remove
        if (r > 0)
            r--;

        s.resize(r);

        return s;
    }
};