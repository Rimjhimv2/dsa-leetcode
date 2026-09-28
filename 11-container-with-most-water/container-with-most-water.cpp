// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int max_water = INT_MIN;
//         for(int i = 0 ; i< n ; i++){
//             for(int j = i+1; j<n ; j++){
//                int water = min(height[i],height[j])*(j-i);
//                 max_water = max(water,max_water);

//             }
//         }
//         return max_water;
//     }
// };

 class Solution {
public:
   int maxArea(vector<int>& height) {
       int n = height.size();
       int left = 0;
       int right = n-1;
       int max_area = INT_MIN;

       while(left<right){

         int area = min(height[left],height[right])*(right-left);
         max_area = max(area,max_area);

         if(height[left] < height[right]){
            //ager left chota hai toh left ko badha karne ki koosish karo hume jyada se jayada paani bahrna hai 
            left++;
         }
         else{
            right--;
         }



       }


return max_area;
   }
 };
