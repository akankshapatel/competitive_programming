#include<unordered_map>

class Solution {
    public:

        bool containsDuplicate(vector<int>& nums) {
            // List implementation is O(n^2) solution, gives Time Limit Exceeded
            //         // Better to use a balanced binary search tree for O(nlogn) implementation
            //                 
            //                         // Following is solution with unordered hash maps. These are internally implmented as buckets. For well-defined k buckets, around O(n^2/k) solution
            unordered_map <int, int> map;
            unordered_map <int, int>::iterator foundNum;
            for(int i = 0; i<nums.size(); i++){
                foundNum = map.find(nums[i]);
                if(foundNum != map.end())
                    return true; // contains duplicate, as duplicate found 
                map.insert(pair<int, bool> (nums[i], false));
            }
            return false; // does not contain duplicates as all values could be inserted
        }
};
