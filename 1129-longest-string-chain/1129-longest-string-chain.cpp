class Solution {
public:
static bool comp(string s1, string s2)
    {
        return s1.size()<s2.size();
    }
bool compare(string &s,string &t){
    if(s.size()!=t.size()+1) return 0;
    int f=0,se=0;
    while(f<s.size()){
        if(se<t.size()&&s[f]==t[se]){
            f++;se++;
        }
        else f++;
    }
    if(f==s.size()&&se==t.size()) return 1;
    return 0;
}

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        int maxi=1;
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j])&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};