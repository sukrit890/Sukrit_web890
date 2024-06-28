class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //if(grid[0][0]==1 || grid[n-1][m-1]==1)   return 0;
        if(grid[0][0]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( grid[i][j]==1 && (i!=0 || j!=0)){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int down=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    down=dp[i][j-1];
                }
                dp[i][j]=up+down;
            }
        }
        return dp[m-1][n-1];
    }
};