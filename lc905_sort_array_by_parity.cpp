class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        bool has_odd = false;
        vector<int>::iterator odd, curr;
        int temp;
        
        for (curr = A.begin(); curr != A.end(); curr++) {
            if ((*curr)%2 != 0){
                if(!has_odd) {
                    odd = curr;
                    has_odd = true;
                }       
            }
            else{
                if(has_odd){
                    temp = *curr;
                    *curr = *odd;
                    *odd = temp;
                    odd++;
                }
            }    
        }     
        return A;
    }
};
