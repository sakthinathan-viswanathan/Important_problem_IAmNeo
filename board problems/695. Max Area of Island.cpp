class Solution {
public:

    int dfs(int r,int c,vector<vector<int>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != 1){
            return 0;
        }


        grid[r][c] = 2;

        return 1+ dfs(r+1,c,grid)+
                dfs(r-1,c,grid)+
                dfs(r,c+1,grid)+
                dfs(r,c-1,grid);


        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int count = 0;

                if(grid[i][j] == 1){
                  int count =  dfs(i,j,grid);
                    res = max(res,count);
                }
            }
        }

        return res;
    }
};
