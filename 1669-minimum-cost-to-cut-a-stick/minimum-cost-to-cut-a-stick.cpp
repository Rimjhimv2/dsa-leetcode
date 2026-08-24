class Solution {
public:
int t[103][103];
int solve(vector<int>&cuts,int l,int r){
   if(l+1 == r){
    return 0;
   }

   if(t[l][r] !=-1){
    return t[l][r];
   }
   
    int result = INT_MAX;
    for(int i = l+1; i<=r-1; i++){


 int cost = (cuts[r] - cuts[l])
                     + solve(cuts, l, i)
                     + solve(cuts, i, r);

result = min(result,cost);
    }
    return t[l][r] = result;
}
    int minCost(int n, vector<int>& cuts) {
        //boundary add karni 

        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
    memset(t,-1,sizeof(t));
        sort(cuts.begin(),cuts.end());
        return solve(cuts,0,cuts.size() - 1);
    }
};