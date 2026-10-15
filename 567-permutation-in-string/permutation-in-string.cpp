class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        

        vector<int>hash1(26,0);
        vector<int>hash2(26,0);

        int s1len = s1.size();
        int s2len = s2.size();

        if(s1len > s2len){
            return false;
        }
        int left = 0;
        int right = 0;


        while( right < s1len){
             hash1[s1[right] - 'a']++;
             hash2[s2[right] - 'a']++;
             right++;
        }
        right--;
        while(right < s2len){
            if(hash1 == hash2){
                return true;
            }
            right++;
        
            if(right!=s2len){
                hash2[s2[right]- 'a']++;
                  hash2[s2[left]- 'a']--;
            left++;
            }
        }
        return false;
    }
};