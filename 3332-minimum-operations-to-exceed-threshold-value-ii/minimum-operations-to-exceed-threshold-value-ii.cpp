class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        //min heap banaya
        priority_queue<long long ,vector<long long> ,greater<long long>>pq;

        //ab min heap mai element dalo 

        for(int num: nums){
            pq.push(num);
        }
         
         int count = 0;
        while(pq.size() >= 2 && pq.top() < k){
            long long x = pq.top();
            pq.pop();

            long long y = pq.top();
            pq.pop();


           long long newValue = x * 2 + y;

            pq.push(newValue);
            count++;
        }
        return count;


    }
};