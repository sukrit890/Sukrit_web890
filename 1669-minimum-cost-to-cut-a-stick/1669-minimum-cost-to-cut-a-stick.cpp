class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.emplace_back(n);
        cuts.insert(begin(cuts), 0);
        sort(begin(cuts), end(cuts));
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        for (int i=c; i>=1; i--) {
            for (int j=1; j<=c; j++) {
                if (i > j) continue;
                int ans = INT_MAX;
                for (int k=i; k<=j; k++) {
                    int curr = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    ans = min(ans, curr);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][c];
    }
};