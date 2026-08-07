class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
    priority_queue<int, vector<int>, greater<int>> pq;
   int n = heights.size();

   for(int i = 0 ; i < n-1 ; i++){

    int diff = heights[i+1] - heights[i];

    if(diff <=0) continue;
    //neeche ja rahe to koi brick use nahi 

    pq.push(diff);


    if(pq.size() > ladders){
        bricks-=pq.top();
        pq.pop();
    }
    //ager queue ka size jyada hogya ladder se //man lo ladder toh 2 hi hai or memeber 3 hahi toh 1 ko brick se niptana hooga na 

    if(bricks < 0 ){
        return i ;
    }
    //hum i index tak pahuch chuke hai but ab hmare pass bricks nahi bachi hai toh aage hum afford nahi kar paynge 
   }
   return n-1;
    }
};

