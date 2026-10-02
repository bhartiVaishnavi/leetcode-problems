class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j< board[0].size(); j++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    if(!isValid(i, j, c, board)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isValid(int row, int col, int c, vector<vector<char>>& board){
        for(int i = 0; i< 9; i++){
            if(i != col && board[row][i] == c ) return false;

            if(i != row && board[i][col] == c ) return false;

            int r = 3 * (row / 3) + i / 3;
            int cl = 3 * (col / 3) + i % 3;
            if((r != row || cl != col) && board[r][cl] == c) return false;
        }
        return true;
    }
};