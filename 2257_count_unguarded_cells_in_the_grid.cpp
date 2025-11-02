//approach 1

class Solution {
public:
    void func(int row, int col, vector<vector<int>>& grid) {
        for (int newRow= row - 1; newRow>= 0; newRow--) {
            if (grid[newRow][col] == -1 || grid[newRow][col] == -1) break;
            grid[newRow][col] = 1;
        }
        for (int newRow= row + 1; newRow< grid.size(); newRow++) {
            if (grid[newRow][col] == -1 || grid[newRow][col] == -1) break;
            grid[newRow][col] = 1;
        }
        for (int newCol= col - 1; newCol>= 0; newCol--) {
            if (grid[row][newCol] == -1 || grid[row][newCol] == -1) break;
            grid[row][newCol] = 1;
        }
        for (int newCol= col + 1; newCol< grid[row].size(); newCol++) {
            if (grid[row][newCol] == -1 || grid[row][newCol] == -1) break;
            grid[row][newCol] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto guard : guards) {
            grid[guard[0]][guard[1]] = -1;
        }

        for (auto wall : walls) {
            grid[wall[0]][wall[1]] = -1;
        }

        for (auto guard : guards) {
            func(guard[0], guard[1], grid);
        }

        int count = 0;
        for (auto row : grid) {
            for (auto cell : row) {
                if (cell == 0) count++;
            }
        }
        return count;
    }
};



//approach 2

class Solution {
public:
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int row, int col, vector<vector<int>>& grid, int dir){
        int newRow = row + directions[dir].first;
        int newCol = col + directions[dir].second;

        if(newRow<0 || newRow>=grid.size() || newCol<0 || newCol>=grid[0].size() || grid[newRow][newCol]==-1){
            return ;
        }

        grid[newRow][newCol]=1;

        dfs(newRow,newCol, grid, dir);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 2nd approach
        vector<vector<int>> grid(m, vector<int>(n,0));

        for(auto wall:walls){
            grid[wall[0]][wall[1]] = -1;
        }
        for(auto guard:guards){
            grid[guard[0]][guard[1]] = -1;
        }

        for(auto guard:guards){
            for(int dir =0 ; dir<directions.size();dir++){
                dfs(guard[0],guard[1],grid,dir);
            }
        }

        // we have made the walls and guards as -1
        // the cells that are guarded by guards as 1
        // now the cells that are not guarded are having initial values of 0

        // so cnt

        int cnt=0;
        for(auto row:grid){
            for(auto cell:row){
                if(cell==0) cnt++;
            }
        }

        return cnt;
    }
};
