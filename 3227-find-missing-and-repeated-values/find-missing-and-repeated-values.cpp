// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int n = grid.size();
//         unordered_map<int, int> mp;

//         for(int i = 0 ; i<n;i++){
//             for(int j = 0 ; j< n ; j++){
//                 mp[grid[i][j]]++;
//             }
//         }

//         int repeating = -1;
//         int duplicating = -1;
//         for(int num = 1 ; num<=n* n ; num++){
//            if(mp[num]==2){
//             repeating= num;
//            }
//            if(mp[num]==0){
//             duplicating = num;
//            }
//         }

//         return {repeating, duplicating};
//     }
// };

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

    int n = grid.size();
    long long  N = n* n ;
    long long  gridSum=0;
    long long  gridsqSum= 0;
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j < n ; j++){
            gridSum += grid[i][j];
            gridsqSum += grid[i][j]* grid[i][j];
        }
    }
    long long Sum = (N* (N+1))/2;
    long long sqSum= (N*(N+1)*(2*N+1))/6;

    int sqDiff = gridsqSum - sqSum;
    int sumDiff = gridSum - Sum ; 

    int a = (sqDiff/sumDiff + sumDiff)/2;
    int b = (sqDiff/sumDiff - sumDiff)/2;

return { a, b };

  }
};
