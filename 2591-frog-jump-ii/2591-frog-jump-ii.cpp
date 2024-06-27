class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int dp[n];
        dp[0]=0;
        dp[1]=stones[1]-stones[0];
        if(n==2)
            return dp[1];
        dp[2]=stones[2]-stones[0];
        for(int i=3;i<n;i++){
            dp[i]=max(dp[i-1],stones[i]-stones[i-2]);
        }
        return dp[n-1];
    }
};