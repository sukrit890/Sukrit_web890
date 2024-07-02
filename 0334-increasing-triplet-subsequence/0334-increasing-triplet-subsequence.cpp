class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp;
        for(int i=0;i<n;i++){
            int idx=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
            if(dp.size()>idx) dp[idx]=arr[i];
            else dp.push_back(arr[i]);
        }
        if(dp.size()>=3) return true;
        else return false;
    }
};