class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& A) {
            int temp;
            int numRow = A.size();
            int numCol = A[0].size();
            vector<vector<int>> B;
            B.resize(numCol);
            for(int col=0; col<numCol; col++)
                B[col].resize(numRow);

            for(int i=0; i< numRow; i++){
                for(int j=0; j< numCol; j++){
                    B[j][i] = A[i][j];
                }
            }

            return B;
        }
};
