class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int maxOnes = 0, currOnes;
            bool continuous = false;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==1){
                    if(!continuous){
                        continuous = true;
                        currOnes = 0;
                    }
                    if(++currOnes>maxOnes)
                        maxOnes = currOnes;
                }
                else{
                    continuous = false;
                    currOnes=0;
                }
            }
            return maxOnes;
        }
};
