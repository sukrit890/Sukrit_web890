int dp[1001];
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        memset(dp,1,sizeof(dp));
        int n=nums.size();
        vector<int>hsh(n,0);
        int last_ind=-1;
        vector<int>temp;
        int maxi=INT_MIN;
        for(int i=0;i<n;++i) hsh[i]=i;
        for(int i=0;i<n;++i)
        {
            for(int prev=0;prev<=i-1;++prev)
            {
                if(nums[i]%nums[prev]==0 and dp[prev]+1>dp[i])
                {
                    dp[i]=dp[prev]+1;
                    hsh[i]=prev;
                }

            }       
            while(dp[i]>maxi)
            {
                last_ind=i;
                maxi=dp[i];

            }
        }
        temp.push_back(nums[last_ind]);
        while(hsh[last_ind]!=last_ind)
        {
            temp.push_back(nums[hsh[last_ind]]);
            last_ind=hsh[last_ind];
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};