class Solution {
public:
    int secondHighest(string s) {
        int n = s.length();
        vector<int> digits;
        for(int i=0; i<n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int temp = s[i] - '0';
                digits.push_back(temp);
            }
        }

        if(digits.size() <= 1){
            return -1;
        }
        
        int largest = -1, secondLargest = -1;
        for(int i=0; i<digits.size(); i++){
            largest = max(largest, digits[i]);
        }
        for(int i=0; i<digits.size(); i++){
            if(digits[i] > secondLargest && digits[i] < largest){
                secondLargest = digits[i];
            }
        }

        return secondLargest;
    }
};