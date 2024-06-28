class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<long long> deg(n,0);
        for(auto c:roads){
            deg[c[0]]+=1;
            deg[c[1]]+=1;
        }
        sort(deg.begin(),deg.end(),greater<long long>());
        long long ans = 0;
        for(auto c:deg){
            ans+=(c*n);
            n-=1;
        }
        return ans;

        
    }
};