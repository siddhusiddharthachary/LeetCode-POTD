class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k =1 ;k<=60;k++){
            long long S = (1LL * num1) - (1LL*k*num2);
            if(S<=0) continue;

            if(__builtin_popcountll(S)<=k && S>=k){
                return k;
            }
        }
        return -1;
    }
};
