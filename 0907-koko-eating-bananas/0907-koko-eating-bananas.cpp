class Solution {
public:
    
    int findMax(vector<int>& piles)
    {
        int n=piles.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    int calc_time(vector<int>& piles,int hourly, int h)
    {
        int total_hours= 0;
        int n=piles.size();
        for(int i=0; i<n; i++)
        {
            total_hours+= ceil((double)piles[i]/ (double)hourly);
            if(total_hours>h) break;
        }
        return total_hours;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=findMax(piles);

        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int total_hours = calc_time(piles,mid,h);

            if(total_hours<=h)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return s;
    }
};