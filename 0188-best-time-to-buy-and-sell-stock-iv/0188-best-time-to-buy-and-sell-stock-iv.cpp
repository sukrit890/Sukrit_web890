class Solution {
public:
    int maxProfit(int t, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(t+1, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int k = 1; k <= t; k++) {
                    int profit = 0;
                    if (buy == 1) 
                    {
                        int wannaSell = prices[i] + dp[i + 1][0][k - 1];
                        int dontWannaSell = dp[i + 1][1][k];
                        profit = max(wannaSell, dontWannaSell);
                    } 
                    else 
                    {
                        int wannaBuy = -prices[i] + dp[i + 1][1][k];
                        int dontWannaBuy = dp[i + 1][0][k];
                        profit = max(wannaBuy, dontWannaBuy);
                    }

                    dp[i][buy][k] = profit;
                }
            }
        }
        return dp[0][0][t];
    }
};