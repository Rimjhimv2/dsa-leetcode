// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

//         int n = arr.size();
//         priority_queue<vector<double>>pq;
//         for(int i = 0 ; i<n-1;i++){
//             for(int j =0;j<n;j++){
//                 double div = (double)arr[i]/arr[j];
//                 pq.push(vector<double>{div,(double)arr[i],(double)arr[j]});
//                 if(pq.size()>k){
//                     pq.pop();
//                 }
//             }
            
//         }
//         auto rec = pq.top();

//             vector<int>result(2);
//             result[0]=rec[1];
//             result[1]= rec[2];
//             return result ;
//     }
// };

// 2nd approch 
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {


        typedef vector<double>V;
        priority_queue<V,vector<V>,greater<V>>pq;
        int n = arr.size();
        for(int i =0;i<n-1;i++){
          double div = (double)arr[i] / arr[n-1];

            pq.push({div,(double)i,(double)n-1});
        }
        int smallest = 1;
        while(smallest<k){
            V vec = pq.top();
            pq.pop();
            int i = vec[1];
            int j = vec[2]-1;
            pq.push({(double)arr[i]/arr[j],(double)i,(double)j});
            smallest++;
        }
        V vec = pq.top();
        int i = vec[1];
        int j = vec[2];
        return {arr[i], arr[j]};


         }
};