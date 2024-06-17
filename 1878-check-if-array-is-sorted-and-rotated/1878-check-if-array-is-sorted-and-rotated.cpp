class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            
            if(nums[i]<=nums[i+1]){ 
               
                continue;
                
            }
            else{

                 count++;

  if(count>=2){
            
                return false;
            }

                 if(nums[0]<nums[nums.size()-1]){
                   return false;
                 }
             
            }
        }return true;
      
    }
};