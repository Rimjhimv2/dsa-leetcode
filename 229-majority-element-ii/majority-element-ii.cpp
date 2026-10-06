// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();

//         unordered_map<int,int>mp;
//         for(int x: nums){
//             mp[x]++;
//         }
//    vector<int>ans;
//         for(auto it : mp){
//             if(it.second > n/3){
//                 //yaha type int nhi hai yaha vector hai 
//                 //return it.first;
//                 //esiliye esko return nhi kr sakte yeh ek int hai 

//                 ans.push_back(it.first);
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1;
        int candidate2 ;
        int count1 =0;
        int count2 = 0 ;

for(int x : nums){




        if(x== candidate1){
            count1++;
        }

       else if(x== candidate2){
        count2++;
       }
else if(count1 == 0 ){
     candidate1 = x;
     count1 =1;
   
        
}
        else if (count2 == 0){
            candidate2 = x;
            count2=1;

        }

       else{
        count1--;
        count2--;
       }

}
        





count1 = 0;
 count2 = 0;
for(int x : nums){
    if( candidate1 == x){
        count1++;
    }
    else if( candidate2 == x){
        count2++;
    }
}
vector<int>ans;

if(count1> n/3){
    ans.push_back(candidate1);
}
if(count2> n/3){
     ans.push_back(candidate2);
}

return ans;
   }
 };