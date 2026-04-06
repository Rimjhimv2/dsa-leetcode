class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        
        // Step 1: store {enqueue, process, index}
        vector<vector<int>> sortedTasks;
        for(int i = 0; i < n; i++){
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        sort(sortedTasks.begin(), sortedTasks.end());
        
        // Min heap → (processingTime, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> result;
        
        long long curr_time = 0;
        int idx = 0;
        
        while(idx < n || !pq.empty()){
            
            // Agar heap empty hai → time jump karo
            if(pq.empty() && curr_time < sortedTasks[idx][0]){
                curr_time = sortedTasks[idx][0];
            }
            
            // Available tasks ko heap me daalo
            while(idx < n && sortedTasks[idx][0] <= curr_time){
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }
            
            // Process best task
            auto curr_task = pq.top();
            pq.pop();
            
            curr_time += curr_task.first;
            result.push_back(curr_task.second);
        }
        
        return result;
    }
};
//cpu usko sunega jiska duration time 0 hai 

// Steps:
// Tasks ko sort karo enqueueTime ke basis pe
// Ek min heap use karo:
// (processingTime, index)
// Time track karo (curr_time)
// Jo tasks available hain → heap me daalte jao
// Heap se best task nikaal ke process karo