class Solution {
public:
    int findMin(vector<int>& nums) {
        int _min = INT_MAX; // Initialize the minimum value to a large positive integer
        int low = 0, high = nums.size() - 1; // Set the low and high pointers for binary search

        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the middle index

            if (nums[low] <= nums[mid]) {
                // If the left half is sorted (nums[low] <= nums[mid]),
                // update the minimum value and move the low pointer to mid + 1
                _min = min(_min, nums[low]);
                low = mid + 1;
            } else {
                // If the right half is sorted (nums[low] > nums[mid]),
                // update the minimum value and move the high pointer to mid - 1
                _min = min(_min, nums[mid]);
                high = mid - 1;
            }
        }

        return _min; // Return the minimum value found
    }
};