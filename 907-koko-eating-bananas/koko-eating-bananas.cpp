class Solution {
public:
int findmax(vector<int>&piles){
    int n = piles.size();
    int maxi = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        maxi = max(maxi , piles[i]);
    }
    return maxi;
}

long long  TotalHour(vector<int>& piles, int hourly){
    int n = piles.size();
      long long totalH = 0;
    for(int i = 0 ; i<n ; i++){
        totalH+= ceil((double)piles[i]/(double)hourly);

    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        while(low<=high){
            int mid = low + (high - low)/2;
           long long totalH = TotalHour(piles, mid);
            if(totalH <= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};