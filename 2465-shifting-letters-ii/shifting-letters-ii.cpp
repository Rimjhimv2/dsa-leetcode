class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.length();
        vector<int>diff(n);
        for(auto query : shifts){
            int l= query[0];
            int r = query[1];
            int dir = query[2];


           int x;
            if(dir == 0){
                x=-1;
            }
            else{
                x=1;
            }

            diff[l]+=x;
            if(r+1 < n ){
              diff[r+1]-=x;
            } 

            //ab prefix sum 

           
        }

         for(int i = 1; i< n ; i++){
                diff[i]+=diff[i-1];
            }
           // 3. Apply shifts
        for(int i = 0; i < n; i++) {

            int shift = diff[i] % 26;

            s[i] = (s[i] - 'a' + shift + 26) % 26 + 'a';
        } 
        return s; 

    }
};