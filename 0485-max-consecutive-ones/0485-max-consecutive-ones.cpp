class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[i] += nums[i-1];
                maxi = max(maxi, nums[i]);
            }
        }
        return maxi;
    }
};