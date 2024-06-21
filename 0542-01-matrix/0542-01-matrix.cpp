class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0 && !vis[i][j]){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int delr[]={0,-1,0,1};
        int delc[]={1,0,-1,0};
        while(!q.empty()){
            auto node=q.front();
            int r=node.first.first;
            int c=node.first.second;
            int d=node.second;
            q.pop();
            ans[r][c]=d;
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    q.push({{nr,nc},d+1});
                    vis[nr][nc]=1;
                }
            }
        }
        
        return ans;
    }
};