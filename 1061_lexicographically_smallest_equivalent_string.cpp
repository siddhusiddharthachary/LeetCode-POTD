class Solution {
public:
    int parent[26];

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionFind(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY)
            return;
        if (pX < pY) {
            parent[pY] = pX;
        } else {
            parent[pX] = pY;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < s1.size(); i++) {
            unionFind(s1[i] - 'a', s2[i] - 'a');
        }

        string ans = "";
        for (char c : baseStr) {
            ans += (char)(find(c - 'a')) + 'a';
        }

        return ans;
    }
};
