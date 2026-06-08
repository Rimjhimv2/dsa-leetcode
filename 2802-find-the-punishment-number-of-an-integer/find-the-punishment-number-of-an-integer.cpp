class Solution {
public:

    bool check(int i, int currsum, string s, int num) {

        // Base Case
        if (i == s.length()) {
            return currsum == num;
        }

        // Pruning
        if (currsum > num) {
            return false;
        }

        for (int j = i; j < s.length(); j++) {

            string sub = s.substr(i, j - i + 1);
            int val = stoi(sub);

            if (check(j + 1, currsum + val, s, num)) {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {

        int punishment = 0;

        for (int num = 1; num <= n; num++) {

            int square = num * num;
            string s = to_string(square);

            if (check(0, 0, s, num)) {
                punishment += square;
            }
        }

        return punishment;
    }
};