class Solution {
public:
    int n;
    int t[301][5001];

    int solve(int i, vector<int>& coins, int amount) {

        // Base cases
        if (amount == 0)
            return 1;

        if (i == n)
            return 0;

        // Memoization check
        if (t[i][amount] != -1)
            return t[i][amount];

        // If current coin is greater than amount
        if (coins[i] > amount)
            return t[i][amount] = solve(i + 1, coins, amount);

        // Take current coin
        int take = solve(i, coins, amount - coins[i]);

        // Skip current coin
        int skip = solve(i + 1, coins, amount);

        // Store and return answer
        return t[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        n = coins.size();

        memset(t, -1, sizeof(t));

        return solve(0, coins, amount);
    }
};

// umhe diya hai:

// coins[] → alag-alag denominations (jaise ₹1, ₹2, ₹5)
// amount → target paisa

// 👉 Tumhe batana hai:
// kitne different ways (combinations) se amount bana sakte ho


//function kya bnaynge like solve function bnao usme 2 value pass karao ki kis index se start kar rahe ho or kitna amount le rahe ho 

// or base case kayay 
// agar amount 0 hai to return karo 1 ki ek sol mil gaya hai 
//if(amount == 0 ){
    //return 1 ;
//}

//if( i == n ){
    //return 0 ; 
//}

//or agar amount jo cahiye vo kam hai or coin of i ki value jyada hai to return kro ( i+1,amount)

