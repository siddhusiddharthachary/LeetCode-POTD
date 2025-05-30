//dfs approach


class Solution {
public:
    void dfs(vector<int>& edges, int node, vector<int>& dist, int depth) {
        if (node == -1 || dist[node] != -1) return;
        dist[node] = depth;
        dfs(edges, edges[node], dist, depth + 1);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        dfs(edges, node1, dist1, 0);
        dfs(edges, node2, dist2, 0);

        int result = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};


//bfs approach


class Solution {
public:
    void bfs(vector<int>& edges, int start, vector<int>& dist) {
        int n = edges.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int neighbor = edges[node];
            if (neighbor != -1 && !visited[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int minDist = INT_MAX, answer = -1;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    answer = i;
                }
            }
        }

        return answer;
    }
};
