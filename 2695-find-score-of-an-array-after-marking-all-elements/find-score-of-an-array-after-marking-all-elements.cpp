class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        int n = nums.size();
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int, int>>>pq;


//ab queue mai value dal se
for(int i = 0 ; i< n ; i++){
    pq.push({nums[i], i });
}
        vector<bool>marked(n,false);

        long long score = 0 ;
        while(!pq.empty()){


            auto temp = pq.top();
            int value = temp.first;
            int index = temp.second;
            pq.pop();

            if(marked[index]){
              continue;
            }

            //ager nahi hai mark roh score mai value add kaaar or fir mark kar 

            score+= value;
            marked[index] = true;

             if(index > 0){
            marked[index-1] = true;
        }
         //left hai na

         if(index < n-1){
            marked[index + 1 ] = true;
         }

        }

        //ab adjacent k bhi toh mark karna 

       

return score;



    }
};