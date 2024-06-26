class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        int dp[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++)
            dp[i][0] = 0;
        for (int i = 0; i < n + 1; i++)
            dp[0][i] = 0;
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s, t);
    }
    int minInsertions(string s) {
        return (s.length()-longestPalindromeSubseq(s));
    }
    
};