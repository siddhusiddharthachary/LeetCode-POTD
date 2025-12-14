class Solution {
public:
    int getCnt(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                cnt++;
        }
        return cnt;
    }
    string reverseWords(string s) {
        string ans = "";
        vector<string> words;
        int n = s.size();
        int prev = 0;
        string firstWord;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                firstWord = s.substr(prev, i - prev);
                prev = i + 1;
                break;
            }
        }

        if(prev==0) return s;
        int cnt = getCnt(firstWord);
        ans = firstWord;
        int curr = 0;
        for (int i = prev; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                curr++;
            if (s[i] == ' ') {
                string temp = s.substr(prev, i - prev);
                if (curr == cnt) {
                    reverse(temp.begin(), temp.end());
                }
                ans += " " + temp;
                prev = i + 1;
                curr = 0;
            }
        }

        string temp = s.substr(prev);
        if (curr == cnt)
            reverse(temp.begin(), temp.end());
        ans += " " + temp;

        return ans;
    }
};
