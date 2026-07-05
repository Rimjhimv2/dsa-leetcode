class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;

        int left = 0;
        int right = n - 1;

        // Fill left heap
        for (int i = 0; i < candidates && left <= right; i++) {
            leftHeap.push(costs[left]);
            left++;
        }

        // Fill right heap
        for (int i = 0; i < candidates && left <= right; i++) {
            rightHeap.push(costs[right]);
            right--;
        }

        long long ans = 0;

        while (k--) {

            int leftCost = leftHeap.empty() ? INT_MAX : leftHeap.top();
            int rightCost = rightHeap.empty() ? INT_MAX : rightHeap.top();

            if (leftCost <= rightCost) {

                ans += leftCost;
                leftHeap.pop();

//abhi bhi left mai part bacha hu ahaui 
                if (left <= right) {
                    leftHeap.push(costs[left]);
                    left++;
                }

            } else {

                ans += rightCost;
                rightHeap.pop();

                if (left <= right) {
                    rightHeap.push(costs[right]);
                    right--;
                }
            }
        }

        return ans;
    }
};