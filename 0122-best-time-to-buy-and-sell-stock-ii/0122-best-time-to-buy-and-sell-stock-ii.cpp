class Solution {
    int spaceOpti(int n,vector<int>& prices){
        vector<int> next(2,0);
        vector<int> curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int canBuy=0;canBuy<2;canBuy++){
                int profit = 0;
                if(canBuy){
                    int buy = -prices[ind]+ next[0];
                    int notBuy = 0 +  next[1];
                    profit = max(buy,notBuy);
                }
                else{
                    int sell = prices[ind]+ next[1];
                    int notSell = 0 +  next[0];
                    profit = max(sell,notSell);
                }
                curr[canBuy]= profit;
            }
            next = curr;
        }
        return next[1];
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // MEMOIATION
        // bool canBuy = true;
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return solveMemo(0,canBuy,n,prices,dp);

        // TABULATION
        // return solveTabu(n,prices);

        return spaceOpti(n,prices);

    }
};
