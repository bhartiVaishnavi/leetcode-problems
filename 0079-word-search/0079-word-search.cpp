class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, string word, int len, vector<vector<int>>& vis, int di[], int dj[]){
        if(len == word.length()){
            return true;
        }

        for(int ind = 0; ind < 4; ind++){
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            if(nexti >= 0 && nextj >= 0 && nexti < board.size() && nextj < board[0].size() && !vis[nexti][nextj] && board[nexti][nextj] == word[len]){
                
                vis[i][j] = 1;
                if(solve(nexti, nextj, board, word, len + 1, vis, di, dj)){
                    return true;
                }
                vis[i][j] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, +1, 0};

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){

                if(board[i][j] == word[0]){
                    if(solve(i, j, board, word, 1, vis, di, dj)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};