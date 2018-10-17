class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<string> validRecords;
        
        uint16_t current = 0;
        long int sum = 0;
        uint16_t recordSize = ops.size();
        
        while(current < recordSize){
            
            if(strcmp(ops.at(current).c_str(),"C") == 0) {
                string last_valid = validRecords.back();
                validRecords.pop_back();
                sum =  sum - atoi(last_valid. c_str());
            }
            
            else if (strcmp(ops.at(current).c_str(), "D") == 0) {
                string last_valid = validRecords.back();
                int doubleVal = 2 * atoi(last_valid.c_str()) ;
                validRecords.push_back(to_string(doubleVal));
                sum = sum + (doubleVal);
            }
            
            else if (strcmp(ops.at(current).c_str(), "+") == 0) {
                int validSize = validRecords.size();
                int newVal = atoi(validRecords.at(validSize-1).c_str()) + atoi(validRecords.at(validSize - 2).c_str());
                sum = sum + newVal;
                validRecords.push_back(to_string(newVal));
            }
            
            else {
                sum = sum + atoi(ops.at(current).c_str());
                validRecords.push_back(ops.at(current));
            }
            current++;
        }
        
        return sum;
        
    }
};
