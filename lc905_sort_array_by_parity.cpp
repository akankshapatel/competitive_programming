class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        vector <int> oddA, evenA;
        vector<int>::iterator it;
        for (it = A.begin(); it != A.end(); it++) {
            if ((*it)%2 == 0)
                evenA.push_back(*it);
            else
                oddA.push_back(*it);
        }
        
        vector <int> finalA;
        
        for(it = evenA.begin(); it != evenA.end(); it++ )
            finalA.push_back(*it);
        
        for(it = oddA.begin(); it != oddA.end(); it++ )
            finalA.push_back(*it);
        return finalA;
    }
};
