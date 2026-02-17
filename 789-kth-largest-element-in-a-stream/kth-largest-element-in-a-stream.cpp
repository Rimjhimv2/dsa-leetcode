class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>pq;
int k;//imp to declare outside so thai it is accessible
    KthLargest(int k, vector<int>& nums) {
           this->k = k;//main construtor
        for(int i =0;i<nums.size();i++){
            int num =nums[i];
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }

        
    }
    
    int add(int val) {
        
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */