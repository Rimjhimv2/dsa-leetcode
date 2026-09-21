class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int > pos;
        vector<int>neg;

        for(int x : nums){
            if(x> 0){
                pos.push_back(x);
            }
            else{
                neg.push_back(x);
            }
        }

        vector<int>ans;

        for(int i = 0 ; i< pos.size(); i++){
           
           
             ans.push_back(pos[i]);
              ans.push_back(neg[i]);

        }
        return ans;
    }
};