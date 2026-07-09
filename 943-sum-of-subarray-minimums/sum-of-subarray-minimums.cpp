class Solution {
public:

vector<int> getNSL(vector<int>& arr, int n ){
    stack<int>st;

    vector<int>result(n);
    for(int i = 0 ; i < n ; i++){
        if(st.empty()){
            result[i]=-1;
        }

        else{
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

             result[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
    }
    return result;
}


vector<int> getRSL(vector<int>& arr, int n ){
    stack<int>st;

    vector<int>result(n);
    for(int i = n-1 ; i >=0 ; i--){
        if(st.empty()){
            result[i]=n;
        }

        else{
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

             result[i] = st.empty() ? n : st.top();
        }
        st.push(i);
    }
    return result;
}
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int M = 1e9 + 7;
long long sum = 0;
        

        vector<int>NSL = getNSL(arr,n);
        vector<int>RSL = getRSL(arr,n);

        for(int i = 0 ; i< n ; i++){

            long long ls = i-NSL[i];
            long long rs = RSL[i]-i;

            long long totalways = ls*rs;

            sum = (sum + (ls * rs % M) * arr[i]) % M;

        }
        return sum;

    }
};
