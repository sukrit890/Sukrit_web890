
class Solution {
public:
    int mySqrt(int x) {

        int low = 0, high = x;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = mid * mid;
            if (val <= (long long)(x)) {
   
                low = mid + 1;
            }
            else {
            
                high = mid - 1;
            }
        }
        return high;
    }
};