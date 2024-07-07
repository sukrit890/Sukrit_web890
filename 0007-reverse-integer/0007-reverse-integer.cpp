class Solution {
public:
    int reverse(int x) {
        // Initialize the result variable to store the reversed number
        int res = 0;

        // Continue processing while there are digits left in x
        while (x != 0) {
            // Check if the current result will cause overflow or underflow when multiplied by 10
            // INT_MAX/10 is the maximum safe value to multiply by 10 without overflow
            // INT_MIN/10 is the minimum safe value to multiply by 10 without underflow
            if (res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0; // Return 0 to indicate overflow or underflow
            }

            // Multiply the current result by 10 and add the last digit of x
            // x % 10 extracts the last digit of x
            res = res * 10 + x % 10;

            // Remove the last digit from x by performing integer division by 10
            x /= 10;
        }

        // Return the reversed number
        return res;
    }
};