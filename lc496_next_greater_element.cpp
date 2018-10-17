ass Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> outputNums;
        for (int i =0; i<findNums.size(); i++){
            
            // create a stack of nums
            stack<int> numsStack;
            int j;
            for (j=0; j<nums.size(); j++) 
                numsStack.push(nums.at(j));
            
            int ngn = -1; // ngn = next greater number for findNums.at(i)
            while(numsStack.top()){
                if(numsStack.top() > findNums.at(i)) {
                    ngn = numsStack.top();
                }
                else if (numsStack.top() == findNums.at(i)) {
                    break;
                }
                numsStack.pop();
            }
            
            outputNums.push_back(ngn);
        }
        return outputNums;
    }
};
