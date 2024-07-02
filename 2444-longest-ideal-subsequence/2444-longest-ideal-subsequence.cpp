class Solution {
public:
    int IdealStringLengthMemo(int index, string& s, int k, char prev, vector<vector<int>>& dp) {
        if (index < 0) return 0;

        // Determine the index based on prev character
        int prevIndex;
        if (prev == '#') {
            prevIndex = 26;  // Assuming '#' corresponds to index 26
        } else {
            prevIndex = prev - 'a';  // Calculate index for lowercase letters
        }

        if (dp[index][prevIndex] != -1) return dp[index][prevIndex];

        int pick = 0;
        if (prev == '#' || abs(s[index] - prev) <= k) {
            pick = 1 + IdealStringLengthMemo(index - 1, s, k, s[index], dp);
        }

        int notPick = IdealStringLengthMemo(index - 1, s, k, prev, dp);

        return dp[index][prevIndex] = max(pick, notPick);
    }

    int longestIdealString(string s, int k) {
        int size = s.length();
        // dp array with an extra column for the initial '#' character
        vector<vector<int>> dp(size, vector<int>(27, -1));  // Assuming 26 letters + 1 for '#'
        return IdealStringLengthMemo(size - 1, s, k, '#', dp);
    }
};