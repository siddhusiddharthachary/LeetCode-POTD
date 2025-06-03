class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < containedBoxes.size(); i++) {
            for (auto nbr : containedBoxes[i]) {
                graph[i].push_back(nbr);
            }
        }

        int n = candies.size();
        vector<bool> vis(n, false);
        queue<int> q;
        vector<bool> inQueue(n, false); 
        unordered_set<int> pending;   

        for (auto it : initialBoxes) {
            q.push(it);
            inQueue[it] = true;
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            if (!status[box]) {
                pending.insert(box);
                continue;
            }

            if (vis[box]) continue;
            vis[box] = true;
            totalCandies += candies[box];

            for (auto key : keys[box]) {
                status[key] = 1;
                if (pending.count(key)) {
                    q.push(key);
                    pending.erase(key);
                }
            }

            for (auto nbr : graph[box]) {
                if (!inQueue[nbr]) {
                    q.push(nbr);
                    inQueue[nbr] = true;
                }
            }
        }

        return totalCandies;
    }
};
