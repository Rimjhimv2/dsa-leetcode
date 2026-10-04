class Solution {
public:

 int largestRectangleArea(vector<int>& heights){
    int n =  heights.size();
    vector<int>right(n,0);
    vector<int>left(n,0);
    stack<int>st;

    //right smaller element 
    for(int i = n-1; i>=0; i--){
        while(st.size() >0 && heights[st.top()] >= heights[i]){
            st.pop();
        }

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
 while(!st.empty()){
    st.pop();
 }

    //left smaller element 

    for(int i = 0; i<n; i++){
        while(st.size() >0 && heights[st.top()] >= heights[i]){
            st.pop();
        }

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int ans = 0 ; 
    for(int i = 0 ; i< n ; i++){
        int width = right[i]-left[i]-1;
        int area = width * heights[i];
        ans = max(ans,area);
    }
    return ans;
 }
    int maximalRectangle(vector<vector<char>>& matrix) {
         int m = matrix.size();
         int n = matrix[0].size();

         vector<int>height(n,0);
          int ans = 0;
         for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                   height[j]=0; 
                }
            }

            ans = max(ans,largestRectangleArea(height));
         }
         return ans;
    }
};