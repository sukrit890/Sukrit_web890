class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<vector<int>>dp(200,vector<int>(200,-1));
        for(int i = t.size()-1; i>=0; i--){
            for(int j = 0; j<t[i].size(); j++){
                if(i == t.size()-1)
                dp[i][j] = t[i][j];
                else{
                    int down = t[i][j] + dp[i+1][j];
                    int diag = t[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(down,diag);
                }
            }
        }
        return dp[0][0];
    }
};