class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0, digitProduct = 1, N = n;
        while(n){
            int d = n%10;
            digitSum+=d;
            digitProduct*=d;
            n/=10;
        }
        int sum = digitSum + digitProduct;
        return N%sum==0;
    }
};
