class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                prevSmaller[i] = -1;
            else
                prevSmaller[i] = st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Next Smaller or Equal Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nextSmaller[i] = n;
            else
                nextSmaller[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;

            ans = (ans + (left * right % MOD) * arr[i]) % MOD;
        }

        return ans;
    }
};
