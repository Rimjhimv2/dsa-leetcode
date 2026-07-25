class Solution {
public:
    int compareVersion(string version1, string version2) {

         int i = 0;
        int j = 0;
        while(i<version1.size() || j<version2.size()){

            long long num1 = 0;
            long long num2 = 0;
            //string ke ander hai ya nahi or jab tak dot nhi milta ,digit padhte raho
            while(i<version1.size() && version1[i]!='.'){
                num1= num1*10 + (version1[i]-'0');
                //ye standard trick hai string se number bnane ki 
                i++;
            }

            while(j<version2.size() && version2[j]!='.'){
                num2= num2*10 + (version2[j]-'0');
                j++;
            }

            // Compare
            if (num1 > num2)
                return 1;

            if (num1 < num2)
                return -1;

            // '.' ko skip karo
            i++;
            j++;
        }

        return 0;
        
    }
};