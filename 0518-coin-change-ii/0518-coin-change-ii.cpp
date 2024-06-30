class Solution {
public:
    
    int solve(int index,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        // changing params are index and amount
        // so 2d dp 
        
        // base conditions
        if(index==0)
        {
            if(amount%coins[0] == 0)
            {
                // completely divisble
                return 1;
            }
            // else 
            // if not divisble
            return 0;
        }
        
        // if already in dp
        // then return dp
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        
        // now take and not take
        int take = 0;
        // we can take only if the current coin index is lesser than the target
        if(coins[index]<=amount)
            take = solve(index,amount-coins[index],coins,dp);
        
        // not take 
        int notTake = solve(index-1,amount,coins,dp);
        
        return dp[index][amount] = (take+notTake);
    }    
    
    
    int change(int amount, vector<int>& coins) {
        // create a dp array
        vector<vector<int>>dp(coins.size(),vector<int> (amount+1,-1));
        int n = coins.size();
        int ans =  solve(n-1,amount,coins,dp);
        
        return ans;
    }
};