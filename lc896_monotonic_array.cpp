class Solution {
    public:
        bool isMonotonic(vector<int>& A) {
            if(A.size() == 1)
                return true;

            bool increasing;
            int prev = 0, curr = 1;
            while(curr < A.size() && A[prev] == A[curr]){
                prev = curr; 
                curr++;
            }
            if(curr == A.size())
                return true;

            if(A[prev] < A[curr])
                increasing = true;
            else 
                increasing = false;

            while(curr < A.size()){
                if(increasing){
                    if(A[prev] > A[curr]){
                        return false;
                    }
                }
                else{
                    if(A[prev] < A[curr]){
                        return false;
                    }
                }
                prev = curr;
                curr++;
            }   
            return true;
        }
};
