class Solution {
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
            int numRows = A.size();
            int row_num, i, j;
            bool temp;
            for(row_num = 0; row_num < numRows; row_num++){
                for(i=0, j = A[row_num].size()-1; i<j; i++, j--){
                    temp = A[row_num][i];
                    A[row_num][i] = A[row_num][j];
                    A[row_num][j]= temp;
                }
                for(i=0; i<A[row_num].size(); i++){
                    if(A[row_num][i])
                        A[row_num][i] = 0;
                    else 
                        A[row_num][i] = 1;
                }
            }
            return A;
        }
};
