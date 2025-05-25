class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp, pal;

        for (auto word : words) {
            if (word[0] == word[1]) {
                pal[word]++;
            } else {
                mp[word]++;
            }
        }

        int ans = 0;

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            string rev = it->first;
            reverse(rev.begin(), rev.end());
            if (mp.count(rev)) {
                int pairs = min(it->second, mp[rev]);
                ans += pairs * 4;
                mp[rev] = 0; 
            }
        }

        bool hasOdd = false;
        for (auto& [s, freq] : pal) {
            ans += (freq / 2) * 4;
            if (freq % 2 == 1) hasOdd = true;
        }

        if (hasOdd) ans += 2; 

        return ans;
    }
};
