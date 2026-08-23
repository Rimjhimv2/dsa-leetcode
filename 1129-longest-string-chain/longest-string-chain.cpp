class Solution {
public:
int n;

int t[1001][1001];
static bool myfunction(string &word1, string &word2){
    return word1.length() < word2.length();
}

bool isPred(string &prev , string &curr){
    int M = prev.length();
    int N = curr.length();

    if(M>=N || N-M!=1){
        return false;
    }
    int i = 0 ,j =0;
    while(i<M && j<N){
        if(prev[i] == curr[j]){
            i++;
        }
        j++;
    }
    return i==M;
}
int lis(vector<string>& words,int prev_index,int curr_index){

    if(curr_index == n){
        return 0 ;

    }

    if(prev_index!=-1 && t[prev_index][curr_index]!=-1){
        return t[prev_index][curr_index];
    }

    int taken = 0, not_taken = 0;

    if(prev_index == -1 || isPred(words[prev_index],words[curr_index])){
        taken = 1+ lis(words,curr_index,curr_index+1);
    }
    not_taken = lis(words,prev_index,curr_index + 1);

if(prev_index!=-1){
return t[prev_index][curr_index]=max(taken,not_taken);
}
    return max(taken,not_taken);
}
    int longestStrChain(vector<string>& words) {
       n = words.size();
       memset(t,-1,sizeof(t));
        sort(words.begin(),words.end(),myfunction);

        return lis(words,-1,0);
        //prev index -1 hai and 0 current index hai .
    }
};