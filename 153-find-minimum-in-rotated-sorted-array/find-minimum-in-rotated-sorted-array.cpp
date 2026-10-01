class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        while(low<=high){

            //phle pura array mai dkho by any chance sare sorted ho element 
            if(arr[low] <= arr[high]){
                ans = min(ans,arr[low]);
                break;
            }
            int mid = low + (high-low)/2;
            
            //left part sort ho usme min ho element
           if(arr[low] <= arr[mid]){
                ans= min(ans,arr[low]);
                //ab right mai jao ;
                low = mid + 1;
            }
            //right part sorted ho usme min ho element 

            else{
                //rght sorted part mai dekh rahe hai and usme minimum find kar rahe or fir left jao ki usme minimum ho sakta hai 
                ans = min(ans,arr[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};