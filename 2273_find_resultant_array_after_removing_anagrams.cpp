class Solution {
public:
    bool isAnagram(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int i = 1;
        while (i < words.size()) {
            if (isAnagram(words[i - 1], words[i])) {
                words.erase(words.begin() + i);
                if (i > 1) i--;
            } else {
                i++;
            }
        }
        return words;
    }
};
