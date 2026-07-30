class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.size();
        int ans = 0 ; 
        for(int i = 0 ; i<n;i++){
            ans+= (i/8) + 1;
        }
        return ans;
        
    }
};
//mere passs ek phone hai or usme maximum 8 letter assign kiye jate hai 
//phle 8 letter ->1 push
//agle 8 letter-> 2 push
//agle 8 letter->3 push
//aglle 2 letter->4 push

//word type karne ke liye minimum pushes chaiye 

// ex = word = 'abcde'
// sabhi letters alag hai 
// total unique letters = 5 
// phle 8 letters ko 1 push milta hai 


// Tumhe ek word diya hai. Tum phone keypad ki letter mapping apni marzi se change kar sakte ho. Aisi mapping banao ki us word ko type karne ke liye minimum key pushes lagen.
// Ya aur simple:
// Ek word diya hai.
// 2 se 9 tak 8 keys hain.
// Tum letters ko kisi bhi key par rakh sakte ho.
// Har key ka pehla letter = 1 push, doosra = 2 pushes, teesra = 3 pushes, ...
// Minimum total pushes nikalne hain.
// 3014 me saare letters distinct hote hain, isliye:
// Pehle 8 letters → 1 push
// Agle 8 letters → 2 pushes
// Agle 8 letters → 3 pushes
// ... and so on.
