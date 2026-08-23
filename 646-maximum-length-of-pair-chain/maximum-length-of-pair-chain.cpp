class Solution {
public:
int n;
int t[1001][1001];
int lis(vector<vector<int>>& pairs,int prev_idx ,int curr_idx){

    if(curr_idx == n){
        return 0 ;
        //i out of bound hoguya toh return 0 kardo
    }

    if(prev_idx!=-1 && t[prev_idx][curr_idx]!=-1){
        return t[prev_idx][curr_idx];
    }

    int taken = 0;

    if(prev_idx ==-1 || pairs[prev_idx][1] < pairs[curr_idx][0]){
        taken = 1+ lis(pairs,curr_idx,curr_idx+1);
    }

 int not_taken = lis(pairs, prev_idx, curr_idx + 1);

    if(prev_idx!=-1){
        return t[prev_idx][curr_idx]=max(taken,not_taken);

    }

    return max(taken, not_taken);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        memset(t,-1,sizeof(t));
        sort(pairs.begin(),pairs.end());
        return lis(pairs,-1,0);
    } 
};


//yaha bola hai you  can select in any order //so aap sorting kar sakte ho 

