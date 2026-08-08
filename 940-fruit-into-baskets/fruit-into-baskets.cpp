class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < fruits.size(); right++) {

            // Current fruit ko window mein add karo
            mp[fruits[right]]++;

            // Agar 2 se zyada fruit types ho gaye
            while (mp.size() > 2) {

                mp[fruits[left]]--;

                // Agar us fruit ki frequency 0 ho gayi
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            // Current valid window ki length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};


   