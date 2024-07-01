class Solution {
public:
    bool f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (s2[k] != '*')
                    return false;
            }
            return true;
        }
        if (j < 0 && i >= 0)
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        if (s2[j] == '?')
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        if (s2[j] == '*')
            return dp[i][j] =
                       f(i - 1, j, s1, s2, dp) || f(i, j - 1, s1, s2, dp);
        return dp[i][j] = false;
    }
    bool allstars(string s, int idx) {
        for (int i = 0; i < idx; i++) {
            if (s[i] != '*')
                return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int >> dp(n , vector<int >(m  , -1));
        return f(n-1,m-1,s,p,dp);
        // dp[0][0] = true;
        // int i, j;
        // for (i = 0; i <= n; i++)
        //     dp[i][0] = true;
        // for (j = 1; j <= m; j++) {
        //     dp[0][j] = allstars(p, j);
        // }
        // for (i = 1; i <= n; i++) {
        //     for (j = 1; j <= m; j++) {
        //         if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
        //             dp[i][j] = dp[i - 1][j - 1];
        //         } else {
        //             if (p[j - 1] == '*') {
        //                 dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        //             } else {
        //                 dp[i][j] = false;
        //             }
        //         }
        //         //  return f(n-1,m-1,s,p,dp);
        //     }
        // }
        // return dp[n][m];
    }
        };