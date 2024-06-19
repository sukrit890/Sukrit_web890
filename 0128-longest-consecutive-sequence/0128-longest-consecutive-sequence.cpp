class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int cnt=0;
      int maxi=INT_MIN;
      if(nums.size()==1) return 1;
      if(nums.size()==0) return 0;
      sort(nums.begin(),nums.end());
      for(int i=1;i<nums.size();i++){
          if(nums[i]-nums[i-1]==1) cnt++;
          else if(nums[i]-nums[i-1]>=2) cnt=0;
          maxi=max(maxi,cnt);
      }
      return maxi+1;
    }
};