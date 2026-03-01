class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int minPrice = INT_MAX;
        int secPrice = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            
            int price = prices[i];
            if(price<minPrice){
             
                secPrice = minPrice;
                   minPrice = price;
            }
            else{
                secPrice = min(price,secPrice);

            }
        }

        if(minPrice + secPrice > money ){
            return money ;
        }
        return money -(minPrice + secPrice);
    }
};

// 🔷 Ye loop kya karta hai?
// Ye loop array me se:
// Sabse chhota number (minPrice)
// Dusra sabse chhota number (secMinPrice)
// nikaalta hai — wo bhi sirf ek hi traversal me (O(n)), bina sorting ke.
// 🔷 Kaise kaam karta hai?
// Har element ke liye:
// Agar current number minPrice se chhota hai
// → purana minPrice ko secMinPrice bana do
// → current number ko naya minPrice bana do
// Warna
// → check karo kya ye secMinPrice se chhota hai
// → agar haan, to secMinPrice update kar do