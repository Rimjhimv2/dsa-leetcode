class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
             // Hamesha chhoti array par binary search lagao
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

int x = nums1.size();
int y = nums2.size();
int low = 0 ; 
int high = x;
while(low<= high){
      int partitionX = low + (high - low) / 2;
    int partitionY = (x+y+1)/2 - partitionX;

    int maxleftX ;
    if(partitionX == 0 ){
maxleftX = INT_MIN;
    }
    else{
        maxleftX = nums1[partitionX - 1];
    }

    int minrightX;
    if(partitionX == x ){
        minrightX = INT_MAX;
    }
    else{
minrightX = nums1[partitionX];
    }

    int maxleftY;
    if(partitionY == 0 ){
        maxleftY = INT_MIN;
    }
    else{
        maxleftY = nums2[partitionY- 1];
    }
    int minrightY;
    if(partitionY == y ){
        minrightY = INT_MAX;
    }
    else{
        minrightY = nums2[partitionY];
    }


    //partion hogya ab dekh kya valid hai ya nahi 
   // Kya partition sahi hai?
            if (maxleftX <= minrightY &&
                maxleftY <= minrightX) {

        if((x+y)%2 == 0 ){
        return (max(maxleftX, maxleftY) +
        min(minrightX, minrightY)) / 2.0;
        }

        else{
            return max(maxleftX, maxleftY);
        }
    }

   else if (maxleftX > minrightY) {

                high = partitionX - 1;
            }

            // Partition ko right shift karo
            else {

                low = partitionX + 1;
            }
        }

        return 0.0;
    
}

    
};