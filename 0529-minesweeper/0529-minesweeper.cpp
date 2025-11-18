class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0], col = click[1];
        
        // If clicked on mine, game over
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }
        
        // Otherwise, reveal the square using DFS
        dfs(board, row, col);
        return board;
    }
    
private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'E') {
            return;
        }
        
        // Count adjacent mines
        int mines = countAdjacentMines(board, row, col);
        
        if (mines > 0) {
            // Reveal with mine count
            board[row][col] = '0' + mines;
        } else {
            // Reveal as blank and recursively reveal adjacent
            board[row][col] = 'B';
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue;
                    dfs(board, row + dr, col + dc);
                }
            }
        }
    }
    
    int countAdjacentMines(vector<vector<char>>& board, int row, int col) {
        int count = 0;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                int nr = row + dr, nc = col + dc;
                if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                    if (board[nr][nc] == 'M') count++;
                }
            }
        }
        return count;
    }
};