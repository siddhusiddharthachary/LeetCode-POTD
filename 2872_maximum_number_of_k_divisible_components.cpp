class Solution {
public:
    long long dfs(int node, int parent, const vector<vector<int>> &adj, const vector<int>& values, int& res, int k){
        long long preSum = values[node];
        for(int child:adj[node]){
            if(child==parent) continue;
            preSum+=dfs(child,node,adj,values,res,k);
        }
        if(preSum%k==0){
            ++res;
            return 0;
        }
        return preSum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(0,-1,adj,values,res,k);
        return res;
    }
};
