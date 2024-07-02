class Solution {
public:
      int min(int a, int b){
        if(a > b) return b;
        return a;
    }
    int solution(int index, vector<int>& arr, int k, vector<int> &dp){
        if(index == arr.size()) return 0;
        if(dp[index] != -1) return dp[index];

        int maxSum = 0;
        int maxi = 0, len = 0;
        for(int j=index; j<min(index+k, arr.size()); ++j){
            maxi = max(maxi, arr[j]);
            len++;
            int sum = len*maxi + solution(j+1, arr, k, dp);
            maxSum = max(maxSum, sum);
        }

        return dp[index] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, -1);
        return solution(0, arr, k, dp);
    }
};