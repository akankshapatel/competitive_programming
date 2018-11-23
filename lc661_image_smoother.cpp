class Solution {
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
            int numRows = M.size();
            int numCols = M[0].size();

            if(numRows == 1 && numCols == 1)
                return M;

            vector<vector<int>> mSmooth;
            mSmooth.resize(numRows);
            for(int i=0; i<numRows; i++)
                mSmooth[i].resize(numCols);

            int sum, num;
            for(int r = 0; r<numRows; r++){
                for(int c = 0; c<numCols; c++){
                    sum =M[r][c];
                    num = 1;
                    if(r-1 >= 0){
                        sum+= M[r-1][c];
                        num++;
                    }   
                    if(c-1 >= 0){
                        sum += M[r][c-1];
                        num++;
                    }
                    if(r+1 < numRows){
                        sum += M[r+1][c];
                        num++;
                    }
                    if(c+1 < numCols){
                        sum += M[r][c+1];
                        num++;
                    }
                    if(r-1 >= 0 && c-1 >= 0){
                        sum += M[r-1][c-1];
                        num++;
                    }
                    if(r-1 >= 0 && c+1 < numCols){
                        sum += M[r-1][c+1];
                        num++;
                    }
                    if(r+1 < numRows && c-1 >= 0){
                        sum += M[r+1][c-1];  
                        num++;
                    }
                    if(r+1 < numRows && c+1 < numCols){
                        sum += M[r+1][c+1];
                        num++;
                    }
                    mSmooth[r][c]  = sum/num;
                }
            }
            return mSmooth;
        }
};
