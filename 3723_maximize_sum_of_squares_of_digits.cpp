class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = string(num,'0');
        if(sum<10){
            ans[0] = '0'+sum;
        }
        if(sum>(9*num)){
            return "";
        }
        int k = sum/9;
        int remain = sum%9;
        for(int i=0;i<k;i++){
            ans[i] = '9';
        }
        ans[k] = '0'+remain;
        return ans;
    }
};
