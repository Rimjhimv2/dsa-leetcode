// Tumhe banana hai:
// ➡️ aisi string jisme koi duplicate character na ho
// ➡️ aur length maximum ho
// 🧠 Overall idea
// 👉 Har string ke liye 2 choice:
// include karo
// skip karo
// 👉 Lekin include tabhi:
// jab characters repeat na ho


class Solution {
public:

    // Check if string itself has duplicates
    bool isUnique(string s){
        for(int i = 0; i < s.length(); i++){
            for(int j = i + 1; j < s.length(); j++){
                if(s[i] == s[j]){
                    return false;
                }
            }
        }
        return true;
    }

    // Check if temp + s has duplicates
    bool canCombine(string &temp, string &s){
        for(int i = 0; i < temp.length(); i++){
            for(int j = 0; j < s.length(); j++){
                if(temp[i] == s[j]){
                    return false;
                }
            }
        }
        return true;
    }

    int solve(int i, vector<string>& arr, string temp){

        //bbase case sab string dekhli fir kya return kro length ko 
        if(i == arr.size()){
            return temp.length();
        }

        int include = 0, exclude = 0;

        // Exclude
        exclude = solve(i + 1, arr, temp);

        // Include (only if valid)
        if(isUnique(arr[i]) && canCombine(temp, arr[i])){
            include = solve(i + 1, arr, temp + arr[i]);
        }

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        return solve(0, arr, "");
    }
};