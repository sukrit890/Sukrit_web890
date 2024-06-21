class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid) {
           int m = grid.size();  
         int n = grid[0].size(); 
         vector<vector<int>> vis(m,vector<int>(n,0));
            queue<pair<int,int>> q;
            vector<int> delrow = {-1,0,1,0};
            vector<int> delcol = {0,-1,0,1};
         //Checking on the first and last row
          for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 || j==0 || i==m-1 || j==n-1){
                        if(grid[i][j]==1){
                            vis[i][j]=1; //Marking visited
                            q.push({i,j});
                        }
                    }
                }
          }        
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow = r+delrow[i];
                    int ncol = c+delcol[i];
                      if(nrow>=0 && ncol>=0 && nrow<m && ncol<n &&
                      vis[nrow][ncol]==0 && grid[nrow][ncol]==1){

                      vis[nrow][ncol]=1; //Marking visited
                      q.push({nrow,ncol});
                      }
                }
            }

        //Loop for checking unvisited 1s remaining
         int cnt=0;
         for(int i=0;i<m;i++){
             for(int j =0;j<n;j++){
                   if(vis[i][j]==0 && grid[i][j]==1){
                    
                       cnt++;
                   }
             }
         }
         return cnt;
    }
};