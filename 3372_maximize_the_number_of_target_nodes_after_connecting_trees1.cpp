class Solution {
public:
    int BFS(vector<vector<int>>& tree, int start, int k) {
        int n = tree.size();
        vector<int> dist(n, -1);
        dist[start] = 0;
        int cnt = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto neighbor : tree[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    if (dist[neighbor] <= k) {
                        cnt++;
                        q.push(neighbor);
                    }
                }
            }
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> tree1(n), tree2(m);
        for (const auto edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
        for (const auto edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }
        if (k == 0)
            return vector<int>(n, 1);

        vector<int> reachable1(n, 0), reachable2(m, 0);
        for (int i = 0; i < n; i++) {
            reachable1[i] = BFS(tree1, i, k);
        }
        int maxReach = 0;
        for (int i = 0; i < m; i++) {
            reachable2[i] = BFS(tree2, i, k - 1);
            maxReach = max(maxReach, reachable2[i]);
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] += reachable1[i] + maxReach;
        }
        return ans;
    }
};
