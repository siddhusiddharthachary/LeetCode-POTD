class Solution {
public:
    pair<int, int> getBoustrophedonPosition(int num, int n) {
        int row_from_bottom = (num - 1) / n;
        int offset = (num - 1) % n;
        int row = n - 1 - row_from_bottom;
        int col = (row_from_bottom % 2 == 0) ? offset : n - 1 - offset;
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; 
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            cout<<curr<<" "<<moves<<endl;
            q.pop();

            if (curr == n * n) return moves;

            for (int dice = 1; dice <= 6; ++dice) {
                int next = curr + dice;
                if (next > n * n) break;

                auto [r, c] = getBoustrophedonPosition(next, n);
                if (board[r][c] != -1) {
                    if (board[r][c] <= n * n) {
                        next = board[r][c];
                    }
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1; 
    }
};
