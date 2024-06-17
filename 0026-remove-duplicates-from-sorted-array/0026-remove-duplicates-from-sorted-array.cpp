class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // Initialize a pointer i to keep track of the position to replace the duplicate elements
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) { // If the current element is not equal to the previous element
                i++; // Move the pointer i to the next position
                nums[i] = nums[j]; // Replace the element at position i with the current element
            }
        }
        return i + 1; // Return the length of the resulting array after removing duplicates
    }
};