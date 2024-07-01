class Solution { 
         int dp[50001][2]; 

     int solve(int i,vector<int>&prices,int fee,int buy){

         if(i==prices.size()) return 0 ;

         if(dp[i][buy]!=-1) return dp[i][buy] ;

          if(buy){

               return  dp[i][buy]= max(-prices[i]+solve(i+1,prices,fee,0),solve(i+1,prices,fee,1)) ;
          }

           return  dp[i][buy]= max(prices[i] - fee+solve(i+1,prices,fee,1),solve(i+1,prices,fee,0)) ;


     }
public:
    int maxProfit(vector<int>& prices, int fee) {
      
          memset(dp,-1,sizeof(dp)) ;
         

       return  solve(0,prices,fee,1) ;

    }
};