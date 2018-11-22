class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            int numRows = matrix.size();
            int numCols = matrix[0].size();

            if(numRows == 1 || numCols == 1)
                return true;

            int val, r, c;
            for(c=0; c<numCols; c++){
                val = matrix[0][c];
                for(r=1; r<numRows; r++){
                    if(r+c >= numCols)
                        break;
                    else if(matrix[r][r+c] != val)
                        return false;
                }
            }

            for(r=1; r<numRows; r++){
                val =matrix[r][0];
                for(c=1; c<numCols; c++){
                    if(r+c >= numRows)
                        break;
                    else if (matrix[r+c][c] != val)
                        return false;
                }
            }

            return true;
        }
};
