class Solution {
public:
int maxValue(vector<int>& bloomDay){
    int maxi = INT_MIN;
    int n = bloomDay.size();
    for(int i = 0 ; i< n ; i++){
        maxi = max(maxi,bloomDay[i]);

    }
    return maxi;
}

int minValue(vector<int>& bloomDay){
    int n = bloomDay.size();
    int mini = INT_MAX;
    for(int i = 0 ; i<n;i++){
        mini = min(mini, bloomDay[i]);
    }
    return mini;
}

int possible(vector<int>& bloomDay, int day, int m, int k) {
//m no of bouquet hai 
//k etne boqye adjacent ho 
    int count = 0;
    int bouquet = 0;

    for(int i = 0; i < bloomDay.size(); i++) {

        if(bloomDay[i] <= day) {
            //that eans blooming is possible
            count++;

           
        }
        else {
            bouquet += count/k;
            count = 0;
        }
    }

     bouquet += count/k;
    return bouquet >= m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {


        // Required flowers > available flowers
        if(1LL * m * k > bloomDay.size()) {
            return -1;
        }
        int low = minValue(bloomDay);
        int high = maxValue(bloomDay);

        while(low<= high){
            int mid = low + (high - low)/2;
            if(possible(bloomDay, mid, m, k)) {
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return low;
    }
};