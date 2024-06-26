class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> ds;
       findCombination(0,candidates,target,ans,ds);
       return ans; 
    }
    void findCombination(int index,vector<int>&  arr,int target,vector<vector<int>> &ans,vector<int> &ds){
        //base Condition
        if(index == arr.size()){
            if(target == 0)
                ans.push_back(ds);
            return;
        }

        // Pick Condition
        if(arr[index]<= target){
            ds.push_back(arr[index]);
            findCombination(index,arr, target-arr[index],ans,ds);
            ds.pop_back();
        }
        findCombination(index+1, arr, target, ans, ds);
    }
};