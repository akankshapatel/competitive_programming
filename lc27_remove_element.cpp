class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int next=0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==val) 
                    continue;
                nums[next] = nums[i];
                next++;
            }
            return next;
        }
};
