#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;  // to store seen elements
        
        for(int i = 0; i < arr.size(); i++) {
            int x = arr[i];
            
            // check if double or half exists
            if(s.count(2 * x) || (x % 2 == 0 && s.count(x / 2))) {
                return true;
            }
            
            // insert current element into set
            s.insert(x);
        }
        
        return false; // no such pair found
    }
};