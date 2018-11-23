/* #define <unordered_map> */
#include<math.h>
class Solution {
    public:

        vector<int> twoSum(vector<int>& numbers, int target) {
            /* since array is sorted we can search for the second element. TIme complexityO(nlogn) and space complexity O(1) */ 
            int target_num;
            int low = 0, high = numbers.size()-1, mid;

            for(int i=0; i< numbers.size(); i++){
                target_num = target - numbers[i];
                low = i+1;
                high = numbers.size()-1;
                while(low <= high){
                    mid = floor((high + low)/2);
                    if(target_num == numbers[mid]){
                        vector <int> ans;
                        ans.push_back(i+1);
                        ans.push_back(mid+1);
                        return ans;
                    }
                    else if (target_num < numbers[mid]){
                        high = mid-1;
                        if(high<i)
                            break; /* not in range [i+1,numbers.size()-1] */
                    }
                    else {
                        low = mid+1;
                        if(low > numbers.size()-1)
                            break; /* not in range [i+1,numbers.size()-1] */
                    }
                }
            }

#ifdef COMMENT   
            /* following solution's time complexity is O(n^2), and space complexity is O(n)*/
            unordered_map <int,int> m;
            unordered_map <int,int>::iterator found;
            int target_num;
            for(int i=0; i< numbers.size(); i++){
                target_num = target - numbers[i];
                found = m.find(target_num);
                if(found != m.end()){
                    vector<int> ans;
                    ans.push_back(found->second);
                    ans.push_back(i+1);
                    return (ans); /* return index of first number and this number (index starting from 1) */
                }
                m.insert(pair<int,int>(numbers[i], i+1)); /* insert number and its index (index starting from 1) */
            }
#endif
        }

};
