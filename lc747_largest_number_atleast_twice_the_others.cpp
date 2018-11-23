class Solution {
    public:
        int dominantIndex(vector<int>& nums) {
            int max1, max2, loc1, loc2; //max1 = largest element, max2 = second largest

            if(nums.size() == 1)
                return 0; // zeroeth element as large as all other elements in the array

            if(nums[0]>=nums[1]){
                loc1 = 0;
                loc2 = 1;
                max1 = nums[0];
                max2 = nums[1];
            }
            else{
                loc1 = 1;
                loc2 = 0;
                max1 = nums[1];
                max2 = nums[0];
            }

            for(int i=2; i<nums.size(); i++){
                if(nums[i]>max1){
                    loc2 = loc1;
                    max2 = max1;
                    loc1 = i;
                    max1 = nums[i];
                }
                else if(nums[i]>max2){
                    loc2 = i;
                    max2 = nums[i];
                }
            }
            if(max1 >= 2* max2)
                return loc1;
            else 
                return -1;
        }
};
