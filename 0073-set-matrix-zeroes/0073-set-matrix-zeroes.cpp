class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0;i < n;i++)
        {
            if(matrix[i][0] == 0)
            {
                col0 = 0;
                //KEEP IN MIND we are storing the value for the leftmost column
            }
//NOTE HERE WE WILL BE STARTING FOR THE J=1 AS J=0 IS REVERSED FOR THE STORING PURPOSE
            for(int j = 1;j < m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i = n-1 ;i >= 0;i--)
        {
            for(int j = m-1;j >= 1;j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        // I TOLD SOMETHING TO YOU TO KEEP IN MIND USE IT HERE checking if col0 == 0 then setting leftmost value to zero
            if(col0 == 0)
            {
                matrix[i][0]  = 0;
            }
        }
    }
};