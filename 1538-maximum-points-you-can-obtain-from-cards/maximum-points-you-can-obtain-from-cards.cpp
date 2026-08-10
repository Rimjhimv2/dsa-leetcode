class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = 0;
        for (int x : cardPoints) {
            total += x;
        }
        ///yaha se total sum nikal hi jata  

       ///hamko k cards uthane hai 
       //or jo cards nhi uthane hai vo beech j=ke hi continous array mai se honge

        // Window size = cards we DON'T take

        int windowSize = n - k;
        //etne size ka subaarya bnao or vo subarray mai se hame nahi uthana hai 

        //ab ek window size tak ka subarray bnao or sum nikal 

        int windowSum = 0;

        // First window
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindow = windowSum;

        // Sliding window
        for (int right = windowSize; right < n; right++) {
            windowSum += cardPoints[right];
            windowSum -= cardPoints[right - windowSize];

            minWindow = min(minWindow, windowSum);
        }

        return total - minWindow;
    }
};