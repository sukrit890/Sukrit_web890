class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        map <int, int> frecv; // to be able to split the 2 halfs easily
        vector <int> v;

        sort (sums.begin(), sums.end()); // in line 18 I want to check future elements in the map (bigger elements)

        for (int i=0; i<n; ++i){
            int sum = sums[1] - sums[0]; // a possible element that will be in the final vector
            vector <int> l, r; // one half with subsets that contain sum and one with subsets that don't 

            bool flag = false; // to know which half to choose -> l or r

            for (int j=0; j<sums.size(); ++j){
                if(!frecv[sums[j]]){ // sum of this subset DOESN'T contain 'sum'
                    l.push_back(sums[j]);
                    frecv[sums[j] + sum]++; // the coresponding subset that DOES contain 'sum'

                    if (sums[j] == 0) // 0 is a constant, that's how I know which half to choose, it has to have 0
                        flag = true;
                    // the half that I choose must contain the EMPTY subset -> 0 (multime vida)
                }   
                else{
                    r.push_back(sums[j]);
                    frecv[sums[j]]--; /// just to have it initialized for future use
                }
            }

            if (flag){
                v.push_back(sum);
                sums = l;
            }
            else{
                v.push_back(-sum);
                sums = r;

                // the elements from r are equal to the elements from l + sum 
                // the elements from l are equal to the elements from r - sum
                // where 0 is => which half I choose => which of the upper affirmations is valid => +sum OR -sum goes in v
            }
        }

        return v;
    }
};