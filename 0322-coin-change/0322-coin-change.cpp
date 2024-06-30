class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1, -1);
        for(int money =0; money<=amount ; money++){
            if(money % coins[0]==0){
                prev[money]= money/coins[0];
            }
            else prev[money] = 1e9;
        }
        for(int ind =1 ; ind < n; ind++){
            vector<int> curr(amount+1, -1);
            for(int amt = 0; amt <= amount; amt++){
                int notPick =0+ prev[amt];
                int pick=1e9;
                if(amt>= coins[ind]){
                    pick=1+curr[amt-coins[ind]];
                }
                curr[amt]=min(notPick,pick);
            }
            prev=curr;
        }
        int ans=prev[amount];
        if(ans >= 1e9)  return -1;
        return ans;
    }
};