class Solution {
public:
    int mn = INT_MAX;
    int mx = INT_MIN;

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> arr(n);
        for(int i = 1; i <= n; i++) arr[i - 1] = i;
        dfs(arr, 1, firstPlayer, secondPlayer);
        return {mn, mx};
    }

private:
    void dfs(vector<int>& arr, int round, int firstPlayer, int secondPlayer) {
        int n = arr.size();
        int size = n / 2;

        for(int i = 0; i < size; i++) {
            if(arr[i] == firstPlayer && arr[n - i - 1] == secondPlayer) {
                mn = min(mn, round);
                mx = max(mx, round);
                return;
            }
        }

        bool f1 = false, f2 = false;
        for(int i = 0; i < n; i++) {
            if(arr[i] == firstPlayer) f1 = true;
            if(arr[i] == secondPlayer) f2 = true;
        }

        if(!f1 || !f2) return;

        vector<int> nextarr(size + (n % 2));
        int combinations = (1 << size);
        for(int i = 0; i < combinations; i++) {
            int left = 0, right = nextarr.size() - 1;

            for (int j = 0; j < size; j++) {
                if((1 << j) & i) {
                    nextarr[left] = arr[j];
                    left++;
                } else {
                    nextarr[right] = arr[n - j - 1];
                    right--;
                }
            }

            if (n % 2) {
                nextarr[left] = arr[n / 2];
            }

            dfs(nextarr, round + 1, firstPlayer, secondPlayer);
        }
    }
};
