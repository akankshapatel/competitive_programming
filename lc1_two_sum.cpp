class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map <int, int> m;
            unordered_map <int, int>::iterator found;

            for(int i=0; i<nums.size(); i++){
                found = m.find(target-nums[i]);
                if(found != m.end()){
                    vector <int> result;
                    result.push_back(found->second);
                    result.push_back(i);
                    return result;
                }
                m.insert(pair<int, int>(nums[i], i));
            }
        }
};
