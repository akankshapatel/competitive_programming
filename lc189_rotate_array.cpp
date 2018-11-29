class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int num_rot = k%nums.size();
            reverse(nums.begin(), nums.end());
            auto itr = nums.begin();
            for(int i=0; i<num_rot; i++)
                itr++;
            reverse(nums.begin(),itr);
            reverse(itr, nums.end());
        }
};
