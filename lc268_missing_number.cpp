class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            /* FIrst thought, use n sized vector and insert every element at its index. However, the question requested to implement using constant extra space, else my solution could have used a O(n) space. Since, it is inefficient. Hence, solving as follows. */
            int sum = 0, expected_sum = (nums.size()*(nums.size()+1))/2;
            for(int i = 0; i < nums.size(); i++)
                sum += nums[i];
            return expected_sum - sum;

        }
};
