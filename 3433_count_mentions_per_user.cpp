class Solution {
public:
        void incrementIds(const string& s, vector<int>& ans) {
        string temp;
        for (char c : s) {
            if (isdigit(c)) {
                temp.push_back(c);
            } else if (!temp.empty()) {
                int id = stoi(temp);
                ans[id]++;
                temp.clear();
            }
        }
        if (!temp.empty()) {
            int id = stoi(temp);
            ans[id]++;
        }
    }
    
    void calculateOnlineUsers(int time, const vector<vector<pair<int, int>>>& offline, vector<int>& ans) {
        for (int i = 0; i < ans.size(); i++) {
            bool isOffline = false;
            for (const auto& interval : offline[i]) {
                if (interval.first <= time && time <= interval.second) {
                    isOffline = true;
                    break;
                }
            }
            if (!isOffline) {
                ans[i]++;
            }
        }
    }
    
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> ans(n, 0);
        int ALL = 0;
        vector<vector<pair<int, int>>> offline(n);
        vector<int> timeStamps;
        
        for (const auto& event : events) {
            int time = stoi(event[1]);
            string message = event[0];
            
            if (message == "MESSAGE") {
                if (event[2] == "ALL") {
                    ALL++;
                } else if (event[2] != "HERE") {
                    incrementIds(event[2], ans);
                } else {
                    timeStamps.push_back(time);
                }
            } else {
                int id = stoi(event[2]);
                offline[id].push_back({time, time + 59});
            }
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] += ALL;
        }
        
        for (int time : timeStamps) {
            calculateOnlineUsers(time, offline, ans);
        }
        
        return ans;
    }
};
