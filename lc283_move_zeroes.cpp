class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int numZero = 0;
            for (int i=0; i<nums.size(); i++){
                if(nums[i]==0)
                    numZero++;
                else{
                    nums[i-numZero] = nums[i];
                }
            }
            if(numZero == 0)
                return;
            else{
                for(int i=0; i<numZero; i++)
                    nums[nums.size()-i-1]=0;
            }

        }
};
