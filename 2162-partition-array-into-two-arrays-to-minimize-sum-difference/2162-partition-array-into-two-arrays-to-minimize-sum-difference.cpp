class Solution {
public:
// Super Harddddd... Problem

// Asked in big companies like Google,Uber,.....etc.
// TC=O(2^n X log2(n))  MIND: here n=N/2 (agar poora N lenge to TLE aa jayega)
//  Here by using DP Time Complexity bahut zyada high ho jayegi... 
  
    int minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/2;

        // meet in middle approach 
        vector<vector<int>>left(n+1),right(n+1);
        for(int mask=0;mask<(1<<n);mask++){
            int sz=0;int sum1=0,sum2=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    sz++;
                    sum1+=nums[i];
                    sum2+=nums[n+i];
                }
            }
            left[sz].push_back(sum1);
            right[sz].push_back(sum2);
        }

// Sort the right for every size
        for(int sz=0;sz<=n;sz++){
            sort(right[sz].begin(),right[sz].end());
        }

int ans=INT_MAX;
int sum=accumulate(nums.begin(),nums.end(),0);


// Now take (sz) from left and (n-sz) from right and whichever is the minimum will be the answer
        for(int sz=0;sz<=n;sz++){

    for(auto &a:left[sz]){
        int b=(sum-(2*a))/2;
        auto it=lower_bound(right[n-sz].begin(),right[n-sz].end(),b);

        if(it!=right[n-sz].end()){
            int val=abs(sum-(2*(a+*it)));
            ans=min(ans,val);
        }
        if(it!=right[n-sz].begin()){
            it--;
            int val=abs(sum-(2*(a+*it)));
            ans=min(ans,val);
        }
    }
        }


        return ans; 
    }
};