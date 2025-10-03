class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        if(m<3 || n<3)return 0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> minHeap;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    minHeap.push({h[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }


        vector<pair<int,int> > directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int water = 0;
        while(!minHeap.empty()){
            auto [height,cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first, y = cell.second;
            for(auto dir:directions){
                int nx = x + dir.first;
                int ny = y + dir.second;

                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    water+=max(0,height - h[nx][ny]);
                    minHeap.push({max(height, h[nx][ny]), {nx,ny}});
                    vis[nx][ny] = true;
                }
            }

        }
        return water;
            }
};
