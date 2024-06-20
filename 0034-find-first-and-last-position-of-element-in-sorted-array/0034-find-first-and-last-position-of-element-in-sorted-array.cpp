class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        int first = std::lower_bound(nums.begin(), nums.end(), target)
                         - nums.begin();
        int last = std::upper_bound(nums.begin(), nums.end(), target)
                         - nums.begin()-1;
        if (first <= last)
            return {first, last};
        return {-1,-1};
    }
};