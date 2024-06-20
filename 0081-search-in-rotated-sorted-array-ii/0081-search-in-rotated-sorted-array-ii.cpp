class Solution {
public:
    bool search(vector<int>& arr, int t) {
        int n=arr.size();
        int l=0,h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(arr[m]==t) return true;
            if(arr[l]==arr[m] && arr[m]==arr[h]){
                l++;
                h--;
                continue;
            }
            if(arr[l]<=arr[m]){
                if(arr[l]<=t && arr[m]>=t){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else if(arr[m]<=arr[h]){
                if(arr[m]<=t && t<=arr[h]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
        }
        return false;
    }
};