class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int sum = 0, lSum = 0, rSum;
            for(int i=0; i<nums.size(); i++)
                sum += nums[i];

            for(int i=0; i<nums.size(); i++){
                if(i-1 >= 0)
                    lSum += nums[i-1];
                rSum = sum - lSum - nums[i];
                if(lSum == rSum)
                    return i;
            }
            return -1;
        }
};
