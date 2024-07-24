class Solution {
public:

    int getNum(int num, vector<int> mapping){
        if(num < 10) return mapping[num];
        int mappedNum = 0;
        int placeValue = 1;

        while(num){
            int lastDigit = num%10;// Extract the last digit of the number
            int mappedDigit = mapping[lastDigit];// Map the digit using the provided mapping

            mappedNum = mappedNum + (mappedDigit * placeValue);// Reconstruct the mapped number
            
            placeValue = placeValue*10;
            num = num/10;
        }
        return mappedNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for(int i=0; i<n; i++){
            int mappedNum = getNum(nums[i], mapping);// Get the mapped number for each original number


            vec.push_back({mappedNum, i});// Store the mapped number and its original index
        }
        

        sort(begin(vec), end(vec));

        vector<int> result;
        for(auto &i : vec){
            int index = i.second;
            result.push_back(nums[index]);
        }

        return result;

    }
};