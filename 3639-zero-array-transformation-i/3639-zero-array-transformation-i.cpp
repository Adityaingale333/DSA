class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size(), 0);

        for(int i=0; i<queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];

            diff[left] = diff[left] + 1;
            if(right + 1 < nums.size()){
                diff[right + 1] = diff[right + 1] - 1;
            }
        }

        vector<int> result(diff.size(), 0);
        int cumSum = 0;

        for(int i=0; i<diff.size(); i++){
            cumSum = cumSum + diff[i];
            result[i] = cumSum;
        }

        for(int i=0; i<nums.size(); i++){
            if(result[i] < nums[i]){
                return false;
            }
        }
        return true;
    }
};