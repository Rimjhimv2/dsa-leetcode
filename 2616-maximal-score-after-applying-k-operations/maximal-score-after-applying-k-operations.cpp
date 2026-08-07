class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        

        //max heap bana 
        priority_queue<int>pq;

        for(int it : nums){
            pq.push(it);
        }
long long  ans = 0 ;
        while(k--){

            int x = pq.top();
            pq.pop();

            ans+= x;
             pq.push((x+2)/3);



        }

        return ans;

    }
};