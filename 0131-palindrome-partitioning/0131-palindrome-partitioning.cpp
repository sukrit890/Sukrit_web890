class Solution {
private:
    void helper(string s,vector<vector<string>>&ans,vector<string> &ds,int ind){
        if(ind==s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                helper(s,ans,ds,i+1);
                ds.pop_back();
            }
        }
          
    }
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(s,ans,ds,0);
        return ans;
        
    }
};
