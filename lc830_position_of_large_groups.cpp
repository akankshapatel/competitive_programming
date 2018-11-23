class Solution {
    public:
        vector<vector<int>> largeGroupPositions(string S) {
            vector<vector<int>> result;
            vector <int> temp;
            if(S.size()<3){
                return result;
            }
            char prev=S[0];
            int start=0;
            int i;
            for(i=1; i<S.size(); i++){  
                if(S[i] != prev){
                    if(i-start>=3){
                        temp.push_back(start);
                        temp.push_back(i-1);
                        result.push_back(temp);
                        temp.clear();
                    }
                    start = i;  
                }
                prev = S[i];
            }
            if(i-start>=3){
                temp.push_back(start);
                temp.push_back(i-1);
                result.push_back(temp);
            }
            return result;  
        }
};
