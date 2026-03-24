// ///question understanding 
// ///We are given a list of words, and we need to find the length of the longest chain we can form.
// // A word A can come before word B in the chain if we can insert exactly one character into A to make B, without changing the order of existing characters.
// // So essentially, each next word in the chain is formed by adding one letter to the previous word.
// // Our goal is to find the maximum length of such a chain.”



// ///esme main 3 steps hai 
// //1st sorting 
//  //2nd check predecessor 
//  //3rd is lis ka code 
//  ////yaha na sorting karni hai but length ke basis par karni hai 


// class Solution {
// public:
// int n ;
// int t[1001][1001];
// //“Then I created a helper function to check whether one word is a predecessor of another.
// // It checks if we can insert exactly one character into the previous word to form the current word while maintaining order.”
// bool isPred(string& prev,string& curr){
//     int M = prev.length();
//     int N = curr.length();

//     if(M>N || N-M != 1){
//         return false;
//     }
//     int i = 0;
//     int j =0;
//     while(i< M && j<N){
//         if(prev[i] == curr[j])
//           i++;
//         j++;
//     }
//     return i==M;
// }
// static bool myFunction(string &word1,string &word2){
// return word1.length() < word2.length();
// }

// // “I use a recursive function where i is the current index and P is the index of the previously selected word.”
// int lis(vector<string>& words,int P,int i ){
//     if(i==n){
//         return 0;
//     }
//     if(t[i][P+1] != -1)
//     return t[i][P+1];
//     //ham last tak pahuch gye or kuch nhi mila to 0 retur kro
//  int take = 0, skip = 0;
//     if(P==-1 || isPred(words[P],words[i])){
//         //ya toh abhi kuch liya hi nahi (P = -1)
// //ya current word valid hai (previous se 1 char bada hai) 
//         take = 1+ lis(words,i,i+1);
// //ab ham le rahe hai toh ye previous jo hai vo i ban gaya hai and jo current hai vo i+1 
//     }
//     skip = lis(words,P,i+1);
//      return t[i][P+1] = max(take, skip);
// }

//        //ye while loop lagaya jab tak dono string ki length khatm na ho jaye tab tak loop chalaynge 

    

//     int longestStrChain(vector<string>& words) {
//         memset(t,-1,sizeof(t));
//          n = words.size();
//         sort(begin(words),end(words),myFunction);
//         return lis(words,-1,0);
//         // “Finally, I start recursion from index 0 with no previous word selected.”
//     }
// };


// // “At each step, I have two choices:

// // Take the current word if it forms a valid chain
// // Skip the current word”

// // “To optimize, I use a 2D DP array where t[i][P+1] stores the result for a given state.
// // I shift P by +1 because it can be -1.”

// //“I want to highlight that this solution initially is exponential, but with memoization it reduces to O(n² * L), and we can further optimize it using hashmap DP.”


///ab ham bottom up se ye ques solve karenge 

class Solution{
    public:
    int n ;
    bool isPred(string &prev,string &curr){

int M = prev.length();
int N = curr.length();
if(M>N || N-M!= 1){
    return false;
}
int i =0;
int j =0;
while(i<M && j<N){
    if(prev[i]==curr[j]){
        i++;
    }
    j++;
}
return i == prev.length();
    }
         static bool myFunction(string &a, string &b) {
        return a.length() < b.length();
    }
        int longestStrChain(vector<string>&words){
            n= words.size();
            sort(begin(words),end(words),myFunction);
            vector<int>t(n,1);
            int maxL =1;
            //sab ke 1 subsequence hoga hi 
            for(int i =0;i<n;i++){
                for(int j =0; j<i;j++){
                    if(isPred(words[j],words[i])){
                        //“kya words[j] → words[i] ka predecessor hai”
                        t[i]= max(t[i],t[j]+1);
                        maxL = max(maxL,t[i]);
                    }
                }
            }
        
        return maxL;
    }

};