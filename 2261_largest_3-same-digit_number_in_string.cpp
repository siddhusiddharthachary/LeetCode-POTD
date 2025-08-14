class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxi = -1;
        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                char val = num[i] ; 
                maxi = max(maxi, val- '0');
            }
        }
        if (maxi == -1) return "";        
        return string(3, '0' + maxi);        
    }
};
