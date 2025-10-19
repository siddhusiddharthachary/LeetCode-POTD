//dfs 

class Solution {
public:
    set<string> vis;
    string minString;
    string op1(string s, int a){
        for(int i=0;i<s.size();i++){
            if(i%2){
                s[i] = ((s[i] - '0' + a) % 10) + '0';
            }
        }
        return s;
    }
    string op2(string s, int b){
        string temp = s.substr(0,b);
        s.erase(0,b);
        s = s + temp;
        return s;
    }
    void recur(string str, int a, int b){
        if(vis.find(str)!=vis.end()) return;
        minString = min(minString, str);
        vis.insert(str);
        string s1 = op1(str, a);
        string s2 = op2(str, b);
        recur(s1, a, b);recur(s2,a,b);
    }
    string findLexSmallestString(string s, int a, int b) {
        minString = s;
        recur(s,a,b);
        return minString;
    }
};


//bfs

class Solution {
public:
    string op1(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        }
        return s;
    }

    string op2(string s, int b) {
        rotate(s.begin(), s.begin() + b, s.end());
        return s;
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> vis;
        string minStr = s;

        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string curr = q.front(); q.pop();
            minStr = min(minStr, curr);

            string s1 = op1(curr, a);
            string s2 = op2(curr, b);

            if (!vis.count(s1)) {
                vis.insert(s1);
                q.push(s1);
            }
            if (!vis.count(s2)) {
                vis.insert(s2);
                q.push(s2);
            }
        }

        return minStr;
    }
};
