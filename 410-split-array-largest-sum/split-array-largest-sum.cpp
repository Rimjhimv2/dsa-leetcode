
class Solution {
public:

int maxValue(vector<int> &nums){
    int maxi = INT_MIN;
    for(int i = 0 ; i< nums.size(); i++){
        maxi = max(maxi,nums[i]);
    }
    return maxi;
}

int sumofValue(vector<int> &nums){
    int sum = 0;
    int n = nums.size();
    for(int i = 0 ; i< n ; i++){
        sum+=nums[i];
    }
    return sum;
}

int countStudents(vector<int> &nums,int pages){
    int student = 1;
    int pagesStudent = 0;
    //pehle student par abhi ek bhi books nahi hai 
//[25,46,28,49,24]
//starting mai pagesStudent = 0 hai and ab 0+25 ye less hai 71 se so ab pagesstudent hai jo vo 25 ho jayge and same 25 ke sath 46 bhi aayega matlab 1st student ko 25,46 pages mil sakte 
    for(int i = 0; i < nums.size(); i++){
 if((pagesStudent + nums[i]) <= pages){
        pagesStudent += nums[i];
    }
    else{
        student++;
        pagesStudent = nums[i];
    }

    }
    return student;
   
}

    int findPages(vector<int> &nums, int m)  {
        if(m > nums.size())
    return -1;
        int low = maxValue(nums);
        int high = sumofValue(nums);
        int ans = 0;
        while(low<= high){
            int mid = low +(high - low )/2;
            if(countStudents(nums, mid) <= m){
ans = mid;
high = mid-1;

            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};