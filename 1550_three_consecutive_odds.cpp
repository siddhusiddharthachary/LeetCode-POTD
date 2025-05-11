class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return false;
        int i = 2;
        while (i < n) {
            if (arr[i-2] % 2 && arr[i-1] % 2 && arr[i] % 2)
                return true;
            i++;
        }
        return false;
    }
};
