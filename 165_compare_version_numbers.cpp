class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        string s1, s2;

        for (auto c : version1) {
            if (c != '.') s1.push_back(c);
            else { v1.push_back(s1); s1.clear(); }
        }
        v1.push_back(s1);

        for (auto c : version2) {
            if (c != '.') s2.push_back(c);
            else { v2.push_back(s2); s2.clear(); }
        }
        v2.push_back(s2);

        int n1 = v1.size(), n2 = v2.size();
        if (n1 < n2) v1.resize(n2, "0");
        else if (n2 < n1) v2.resize(n1, "0");

        for (int i = 0; i < (int)v1.size(); i++) {
            int a = stoi(v1[i]);
            int b = stoi(v2[i]);
            if (a < b) return -1;
            if (a > b) return 1;
        }

        return 0; 
    }
};
