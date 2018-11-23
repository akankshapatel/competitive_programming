class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
            int numRows = nums.size();
            int numCols = nums[0].size();

            if(numRows*numCols != r*c)
                return nums;

            vector <vector<int>> finalM;
            finalM.resize(r);
            for(int i=0; i<r; i++)
                finalM[i].resize(c);

            int row=0, col=0;
            for(int i=0; i<numRows; i++){
                for(int j=0; j<numCols; j++){
                    finalM[row][col] = nums[i][j];
                    col++;
                    if(col == c){
                        row++;
                        col=0;
                    }
                }
            }
            return finalM;
        }
};
