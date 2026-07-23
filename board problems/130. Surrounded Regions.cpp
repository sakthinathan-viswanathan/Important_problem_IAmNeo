class Solution {
public:

    void dfs(int r,int c,vector<vector<char>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != 'O'){
            return ;
        }

        grid[r][c] = '#';

        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int j = 0; j < m; j++){
            dfs(0, j, grid);
            dfs(n - 1, j, grid);
        }

        for(int i = 0; i < n; i++){
            dfs(i, 0, grid);
            dfs(i, m - 1, grid);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                }
                else if(grid[i][j] == '#'){
                    grid[i][j] = 'O';
                }
            }
        }


    }
};
