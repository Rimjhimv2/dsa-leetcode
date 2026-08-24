class Solution {
public:
int t[501];
int n;

int solve(vector<int>&arr,int idx , int k){

    if(idx >=arr.size()){
        return 0 ; 
        //sum kuch bjhi nhi hoiga 

    }

    if(t[idx]!=-1){
        return t[idx];
    }

    int curr_max = -1;
    int result = 0;

    for(int j = idx ; j< n && j-idx+1 <=k ;j++){
curr_max = max(curr_max,arr[j]);
result = max(result, (j-idx+1)*curr_max + solve(arr,j+1,k));

    }
    return  t[idx]= result;
    

}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        n = arr.size();
        memset(t,-1,sizeof(t));
      return solve(arr, 0, k);
    }
};