#include<bits/stdc++.h>
using namespace std;

void dfs(int r,int c,vector<vector<int>> &grid){
    
    int n = grid.size();
    int m = grid[0].size();
    
    if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != 1){
        return ;
    }
    
    grid[r][c] = 2;
    
    dfs(r+1,c,grid);
    dfs(r-1,c,grid);
    dfs(r,c+1,grid);
    dfs(r,c-1,grid);
    
    
   
    return ;
    
}

int main(){
    
    int n;
    cin>>n;
    
    int m;
    cin>>m;
    
    vector<vector<int>>grid(n,vector<int>(m));
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            cin>>grid[i][j];
        }
    }
    
    int count = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(grid[i][j] == 1){
                dfs(i,j,grid);
                
                count++;
                
            }
        }
    }
    
    cout<<count;
}
